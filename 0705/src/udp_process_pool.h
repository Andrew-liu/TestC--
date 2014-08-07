/*************************************************************************
	> File Name: udp_process_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 05 Jul 2014 03:28:00 PM HKT
 ************************************************************************/

#ifndef _udp_pocess_pool
#define _udp_pocess_pool

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define S_IDLE 0
#define S_BUSY 1

//define status
typedef struct tag
{
	pid_t pid;
	int flag;
	int fd_read;
	int fd_write;
	int cnt;
}Child,*pChild;

typedef struct sockaddr_in SA;
int  make_process_pool(int num,pChild p);
void child_main();
void my_handle(int fd_client,SA *addr,char *send_buf);








#endif

