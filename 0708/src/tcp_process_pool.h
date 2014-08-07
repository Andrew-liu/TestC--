/*************************************************************************
	> File Name: tcp_process_pool.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 08 Jul 2014 02:42:19 PM HKT
 ************************************************************************/

#ifndef _tcp_process_pool
#define _tcp_process_pool

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE);\
	}while(0)
#define S_IDLE 0
#define S_BUSY 1

typedef struct tag
{
	pid_t pid;
	int status;
	int fd_read;
	int fd_write;
	int count;
}Child_info,*pChild_info;
//server
int tcp_init(const char *ip,const int port);
int tcp_accept(int fd_server);
void handle_requst(int fd_client);
void child_main();
int make_process(pChild_info p, int num);
void send_describe(int sockfd,int fd_to_send);
void recv_describe(int sockfd,int *fd_to_recv);
//client
int tcp_connect(const char *ip,int port);
#endif

