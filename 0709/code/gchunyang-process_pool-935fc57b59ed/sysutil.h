#ifndef SYSUTIL_H_
#define SYSUTIL_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <poll.h>
#include <sys/epoll.h>

#define ERR_EXIT(m) \
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0);

#define MAXLINE 1024

ssize_t readn(int fd, void *buf, size_t count);
ssize_t writen(int fd, const void *buf, size_t count);
ssize_t recv_peek(int sockfd, void *buf, size_t len);
ssize_t readline(int sockfd, void *buf, size_t maxline);

//void send_fd(int sock_fd, int send_fd);
//int recv_fd(const int sock_fd);

int send_fd(int sock_fd, int send_fd);
int recv_fd(int sock_fd, ssize_t (*userfunc)(int, const void *, size_t));

#endif /* SYSUTIL_H_ */
