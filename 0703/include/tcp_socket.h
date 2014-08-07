/*************************************************************************
	> File Name: tcp_socket.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 11:59:13 PM HKT
 ************************************************************************/
#ifndef _tcp
#define _tcp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <sys/select.h>
#define SERVER_IP "192.168.1.69"
#define SERVER_PORT 8888

#define MSG_SIZE 8188
#define MSG_LEN  (8192 - MSG_SIZE)
#define S_BUSY 1
#define S_IDLE 0
typedef struct tag
{
	int s_len ;
	char s_buf[MSG_SIZE]; 
}MSG;
typedef struct tag1
{
	pid_t pid;
	int status;
	int fd_read;
	int fd_write;
	int s_cnt;
}Child_info,*pChild_info;
int tcp_init(const char *ip,int port);
int tcp_accept(int fd_server);
int tcp_connect();
void handle_file(int fd_client);
void make_process(pChild_info p,int num);
void child_main();


#endif
