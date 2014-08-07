/*************************************************************************
	> File Name: getsockopt.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 09:29:19 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	int recv_size=0,send_size=0;
	int len_recv = sizeof(int);
	int len_send = sizeof(int);
	
	getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&recv_size,&len_recv);
	getsockopt(fd,SOL_SOCKET,SO_SNDBUF,&send_size,&len_send);
	printf("the recv buf is %d\nThe send buf is %d\n",recv_size,send_size);
}
