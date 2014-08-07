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

#define SERVER_IP "192.168.1.69"
#define SERVER_PORT 8888

#define MSG_SIZE 8188
#define MSG_LEN  (8192 - MSG_SIZE)

typedef struct tag
{
	int s_len ;
	char s_buf[MSG_SIZE]; 
}MSG;
int tcp_init();
int tcp_accept(int fd_server);
int tcp_connect();
void handle_file(int fd_client);


#endif
