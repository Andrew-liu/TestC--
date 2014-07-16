#include "sysutil.h"

ssize_t readn(int fd, void *buf, size_t count) {
	size_t nleft;
	ssize_t nread;		//BUG
	char *ptr;

	ptr = buf;
	nleft = count;

	while (nleft > 0) {
		nread = read(fd, ptr, nleft);
		if (nread < 0) {
			if (errno == EINTR) {
				nread = 0;
			} else {
				return -1;
			}
		} else if (nread == 0) {
			break;
		}
		nleft -= nread;
		ptr += nread;
	}
	return count - nleft;
}

ssize_t writen(int fd, const void *buf, size_t count) {
	size_t nleft;
	ssize_t nwritten;   //这里必须是有符号数！！！
	const char *ptr;

	ptr = buf;
	nleft = count;

	while (nleft > 0) {
		nwritten = write(fd, ptr, nleft);
		if (nwritten < 0) {
			if (errno == EINTR) {
				//nwritten = 0;
				continue;
			} else {
				return -1;
			}
		} else if (nwritten == 0) {
			continue;
		}
		nleft -= nwritten;
		ptr += nwritten;
	}

	return count;
}

ssize_t recv_peek(int sockfd, void *buf, size_t len) {
	int nread;
	while (1) {
		nread = recv(sockfd, buf, len, MSG_PEEK);
		if (nread < 0 && errno == EINTR) {	//被中断则继续读取
			continue;
		}
		if (nread < 0) {
			return -1;
		}
		break;
	}
	return nread;
}

ssize_t readline(int sockfd, void *buf, size_t maxline) {
	int nread;	//一次IO读取的数量
	int nleft;	//还剩余的字节数
	char *ptr;	//存放数据的指针的位置
	int ret;	//readn的返回值
	int total = 0;	//目前总共读取的字节数

	nleft = maxline;
	ptr = buf;

	while (nleft > 0) {
		ret = recv_peek(sockfd, ptr, nleft);
		//注意这里读取的字节不够，绝对不是错误！！！
		if (ret <= 0) {
			return ret;
		}

		nread = ret;
		int i;
		for (i = 0; i < nread; ++i) {
			if (ptr[i] == '\n') {
				ret = readn(sockfd, ptr, i + 1);
				if (ret != i + 1) {
					return -1;
				}
				total += ret;
				return total;	//返回此行的长度 '\n'包含在其中
			}
		}

		ret = readn(sockfd, ptr, nread);
		if (ret != nread) {
			return -1;
		}
		nleft -= nread;
		total += nread;
		ptr += nread;
	}
	return maxline;
}


/*

void send_fd(int sock_fd, int fd) {
	int ret;
	struct msghdr msg;   //要发送的msg
	struct cmsghdr *p_cmsg;
	struct iovec vec;    //填充iov字段，这里无用
	char cmsgbuf[CMSG_SPACE(sizeof(fd))];
	int *p_fds;
	char sendchar[2] = {0};
	msg.msg_control = cmsgbuf;
	msg.msg_controllen = sizeof(cmsgbuf);
	p_cmsg = CMSG_FIRSTHDR(&msg);
	p_cmsg->cmsg_level = SOL_SOCKET;
	p_cmsg->cmsg_type = SCM_RIGHTS;
	p_cmsg->cmsg_len = CMSG_LEN(sizeof(fd));
	p_fds = (int*) CMSG_DATA(p_cmsg);
	*p_fds = fd;

	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &vec;
	msg.msg_iovlen = 1;
	msg.msg_flags = 0;

	vec.iov_base = &sendchar;
	vec.iov_len = sizeof(sendchar);
    printf("send...................\n");
	ret = sendmsg(sock_fd, &msg, 0);
	if (ret != 1)
		ERR_EXIT("sendmsg");
    printf("send finish................\n");
}

int recv_fd(const int sock_fd) {
	int ret;
	struct msghdr msg;
	char recvchar[2] = {0};
	struct iovec vec;
	int recv_fd;
	char cmsgbuf[CMSG_SPACE(sizeof(recv_fd))];
	struct cmsghdr *p_cmsg;
	int *p_fd;
	vec.iov_base = &recvchar;
	vec.iov_len = sizeof(recvchar);
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &vec;
	msg.msg_iovlen = 1;
	msg.msg_control = cmsgbuf;
	msg.msg_controllen = sizeof(cmsgbuf);
	msg.msg_flags = 0;

	p_fd = (int*) CMSG_DATA(CMSG_FIRSTHDR(&msg));
	*p_fd = -1;
    printf("receive..................\n");
	ret = recvmsg(sock_fd, &msg, 0);
	if (ret != 2)
		ERR_EXIT("recvmsg");

    printf("receive. finish...........\n");
	p_cmsg = CMSG_FIRSTHDR(&msg);
	if (p_cmsg == NULL)
		ERR_EXIT("no passed fd");

	p_fd = (int*) CMSG_DATA(p_cmsg);
	recv_fd = *p_fd;
	if (recv_fd == -1)
		ERR_EXIT("no passed fd");

	return recv_fd;
}

*/

#define CONTROLLEN CMSG_LEN(sizeof(int))

static struct cmsghdr *cmptr = NULL;

int send_fd(int sock_fd, int send_fd) {
	struct iovec iov[1];
	struct msghdr msg;
	char buf[2];

	iov[0].iov_base = buf;
	iov[0].iov_len = 2;

	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;

	if (cmptr == NULL) {
		cmptr = malloc(CONTROLLEN);
		if (cmptr == NULL) {
			ERR_EXIT("malloc");
		}
	}

	cmptr->cmsg_level = SOL_SOCKET;
	cmptr->cmsg_type = SCM_RIGHTS;
	cmptr->cmsg_len = CONTROLLEN;
	msg.msg_control = cmptr;
	msg.msg_controllen = CONTROLLEN;
	*(int*) CMSG_DATA(cmptr) = send_fd;
	buf[1] = 0;

	buf[0] = 0;
	if (sendmsg(sock_fd, &msg, 0) != 2) {
		ERR_EXIT("sendmsg");
	}
	return 0;
}

int recv_fd(int sock_fd, ssize_t (*userfunc)(int, const void *, size_t)) {
	int newfd, status;

	char buf[MAXLINE];
	struct iovec iov[1];
	struct msghdr msg;
	status = -1;

	while (1) {
		iov[0].iov_base = buf;
		iov[0].iov_len = sizeof(buf);
		msg.msg_iov = iov;
		msg.msg_iovlen = 1;
		msg.msg_name = NULL;
		msg.msg_namelen = 0;
		if (cmptr == NULL) {
			cmptr = malloc(CONTROLLEN);
			if (cmptr == NULL) {
				ERR_EXIT("malloc");
			}
		}
		msg.msg_control = cmptr;
		msg.msg_controllen = CONTROLLEN;
		int nr = recvmsg(sock_fd, &msg, 0);
		if (nr <= 0) {
			ERR_EXIT("recvmsg");
		}

		char *ptr;
		for (ptr = buf; ptr < &buf[nr];) {
			if (*ptr++ == 0) {
				if (ptr != &buf[nr - 1]) {
					fprintf(stderr, "message format error");
					exit(EXIT_FAILURE);
				}
				status = *ptr & 0xFF;
				if (status == 0) {
					if (msg.msg_controllen != CONTROLLEN) {
						fprintf(stderr, "status = 0 but no fd");
						exit(EXIT_FAILURE);
					}
					newfd = *(int*)CMSG_DATA(cmptr);
				}
				nr -= 2;
			}
		}

		if(nr > 0 && (*userfunc)(STDERR_FILENO, buf, nr) != nr)
			return -1;
		if(status >= 0){
			return newfd;
		}

	}
	return -1;

}

