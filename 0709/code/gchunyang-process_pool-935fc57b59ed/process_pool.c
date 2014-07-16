#include "process_pool.h"
#include "select_t.h"

void child_do_something(int fd);
void do_echo(int peerfd);

void process_pool_do_childs_msg(pool_t *pool, select_t *sel);
int process_find_child(pool_t *pool, int peerfd);

void process_pool_init(pool_t *pool, int size, int listenfd) {
	pool->size_ = size;
	pool->listenfd_ = listenfd;
	int i;
	for (i = 0; i < MAXCHILD; ++i) {
		pool->childs_[i].child_ = -1;
		pool->childs_[i].sockfd_ = -1;
		pool->childs_[i].status_ = BUSY;
	}
	process_pool_fork_child(pool, size);
}

void process_pool_fork_child(pool_t *pool, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		int sockfds[2];
		if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockfds) < 0) {
			ERR_EXIT("socketpair");
		}
		pid_t pid;
		pid = fork();
		if (pid < 0) {
			ERR_EXIT("fork");
		}
		if (pid == 0) {
			close(sockfds[0]);

			child_do_something(sockfds[1]);
			exit(EXIT_SUCCESS);
		} else {
			close(sockfds[1]);
			pool->childs_[i].sockfd_ = sockfds[0];
			pool->childs_[i].child_ = pid;
			pool->childs_[i].status_ = LEISURE;

		}
	}
	process_pool_do_select(pool);
}

void process_pool_do_select(pool_t *pool) {
	select_t sel;
	select_init(&sel, pool->listenfd_);

	int i;
	for (i = 0; i < pool->size_; ++i) {
		//select_add_to_client(&sel, pool->childs_[i].sockfd_);
		select_add_to_client(&sel, pool->childs_[i].sockfd_);
	}

	while (1) {
		int nready = select_do_wait(&sel);
		if (nready == -1) {
			if (errno == EINTR) {
				continue;
			}
			ERR_EXIT("select");
		} else if (nready == 0) {
			continue;
		}
		if (select_is_in_set(&sel, pool->listenfd_)) {
			process_pool_do_accept(pool);
		}
		process_pool_do_childs_msg(pool, &sel);
	}
}

void process_pool_do_childs_msg(pool_t *pool, select_t *sel) {
	int i;
	for (i = 0; i <= sel->maxi_; ++i) {
		int peerfd = sel->clientfd_[i];
		if (peerfd == -1) {
			continue;
		}
		if (select_is_in_set(sel, peerfd)) {
			char buf[1024] = {0};
			int ret = readline(peerfd, buf, 1024);
			if (ret == -1) {
				if (errno == EINTR) {
					continue;
				}
			} else if (ret == 0) {
				continue;
			} else {
				if (memcmp(buf, "finish\n", strlen("finish\n")) == 0) {
					int index = process_find_child(pool, peerfd);
					pool->childs_[index].status_ = LEISURE;
				}
				memset(buf, 0, 1024);
			}
		}
	}
}

int process_find_child(pool_t *pool, int peerfd) {
	int i;
	for (i = 0; i < pool->size_; ++i) {
		if (pool->childs_[i].sockfd_ == peerfd) {
			return i;
		}
	}
	return -1;
}

void process_pool_do_accept(pool_t *pool) {
	while (1) {

		struct sockaddr_in peeraddr;
		bzero(&peeraddr, sizeof peeraddr);
		socklen_t len = sizeof peeraddr;
		int peerfd = accept(pool->listenfd_, (struct sockaddr*) &peeraddr,
				&len);
		if (peerfd == -1) {
			ERR_EXIT("accept");
		}


		fprintf(stdout, "IP = %s, port = %d\n", inet_ntoa(peeraddr.sin_addr),
				ntohs(peeraddr.sin_port));

		int index = process_pool_schedule_child(pool);
		if (index == -1) {
			fprintf(stderr, "schedule fail!\n");
		}
		pool->childs_[index].status_ = BUSY;

		printf("choose the child %d\n", index);

		//kill all child

		send_fd(pool->childs_[index].sockfd_, peerfd);
		close(peerfd);
	}
}

int process_pool_schedule_child(const pool_t *pool) {
	int i;
	for (i = 0; i < pool->size_; ++i) {
		if (pool->childs_[i].status_ == LEISURE) {
			return i;
		}
	}
	return -1;
}

void child_do_something(int sockfd) {
	while (1) {
		int peerfd = recv_fd(sockfd, NULL);
		if(peerfd == -1){
			ERR_EXIT("peerfd");
		}
		do_echo(peerfd);
		//"finish\n"
		int ret = writen(sockfd, "finish\n", strlen("finish\n"));
		if(ret != strlen("finish\n")){
			ERR_EXIT("writen");
		}
	}
}

void do_echo(int peerfd) {

	printf("debug2 ---  %d\n", peerfd);
	char recvbuf[MAXLINE + 1];
	memset(recvbuf, 0x00, sizeof recvbuf);

	while (1) {
		int ret = readline(peerfd, recvbuf, MAXLINE);
		if (ret == -1) {
			ERR_EXIT("readline");
		}
		if (ret == 0) {
			fputs("client close\n", stdout);
			close(peerfd);
			return;
		}
		fprintf(stdout, "receive: %s", recvbuf);
		writen(peerfd, recvbuf, strlen(recvbuf));
		memset(recvbuf, 0x00, sizeof recvbuf);
	}
}
