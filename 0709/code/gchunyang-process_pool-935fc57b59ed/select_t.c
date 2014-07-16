#include "select_t.h"

void select_init(select_t *pool, int listenfd) {
	pool->nready_ = 0;
	pool->maxfd_ = listenfd;
	pool->maxi_ = -1;
	pool->listenfd_ = listenfd;
	int i;
	for (i = 0; i < FD_SETSIZE; ++i) {
		pool->clientfd_[i] = -1;
	}
	FD_ZERO(&pool->allset_);
	FD_ZERO(&pool->readyset_);
	FD_SET(listenfd, &pool->allset_);
}

int select_add_to_client(select_t *pool, int fd) {
	int i;
	for (i = 0; i < FD_SETSIZE; ++i) {
		if (pool->clientfd_[i] == -1) {
			pool->clientfd_[i] = fd;
			if (i > pool->maxi_) {
				pool->maxi_ = i;
			}
			break;
		}
	}
	//too many
	if (i == FD_SETSIZE) {
		fprintf(stderr, "too many clients\n");
		exit(EXIT_FAILURE);
	}
	//加入allset
	FD_SET(fd, &pool->allset_);
	if (fd > pool->maxfd_) {
		pool->maxfd_ = fd;
	}
	return 0;
}

int select_remove_from_client(select_t *pool, int index) {
	if (index >= FD_SETSIZE) {
		return -1;
	}
	int fd = pool->clientfd_[index];
	FD_CLR(fd, &pool->allset_);
	pool->clientfd_[index] = -1;

	pool->maxi_ = select_get_max_i(pool);
	pool->maxfd_ = select_get_max_fd(pool);

	return 0;
}

int select_do_wait(select_t *pool) {
	pool->readyset_ = pool->allset_;
	int nready = select(pool->maxfd_ + 1, &pool->readyset_, NULL, NULL, NULL);
	pool->nready_ = nready;
	return nready;
}

int select_is_in_set(const select_t *pool, int fd) {
	return FD_ISSET(fd, &pool->readyset_);
}

int select_get_max_i(const select_t *pool) {
	int i;
	int maxi = -1;
	for (i = 0; i < FD_SETSIZE; ++i) {
		if (pool->clientfd_[i] != -1) {
			maxi = i;
		}
	}
	return maxi;
}
int select_get_max_fd(const select_t *pool) {
	int i;
	int maxfd = -1;
	for (i = 0; i < FD_SETSIZE; ++i) {
		if (pool->clientfd_[i] > maxfd) {
			maxfd = pool->clientfd_[i];
		}
	}
	return maxfd;
}

/*
void select_do_listenfd(select_t *pool) {
	if (select_is_in_set(pool, pool->listenfd_)) {
		struct sockaddr_in peeraddr;
		bzero(&peeraddr, sizeof peeraddr);
		socklen_t len = sizeof peeraddr;

		int peerfd = accept(pool->listenfd_, (struct sockaddr*) &peeraddr,
				&len);
		if (peerfd == -1) {
			ERR_EXIT("accept");
		}
		select_add_to_client(pool, peerfd);
		fprintf(stdout, "IP = %s, port = %d\n", inet_ntoa(peeraddr.sin_addr),
				ntohs(peeraddr.sin_port));
	}
}


void select_do_clientfd(select_t *pool) {
	int i;
	for (i = 0; i <= pool->maxi_; ++i) {
		int peerfd = pool->clientfd_[i];
		if (peerfd == -1) {
			continue;
		}
		if (select_is_in_set(pool, peerfd)) {
			char recvbuf[MAXLINE + 1] = { 0 };
			int ret = readline(peerfd, recvbuf, MAXLINE);
			if (ret == -1) {
				ERR_EXIT("readline");
			}
			if (ret == 0) {
				fputs("client close\n", stdout);
				select_remove_from_client(pool, i);
				close(peerfd);
				continue;
			}
			fprintf(stdout, "receive: %s", recvbuf);
			writen(peerfd, recvbuf, strlen(recvbuf));
		}
	}
}

*/
