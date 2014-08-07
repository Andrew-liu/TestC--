/*************************************************************************
	> File Name: tcp_connect.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 01:15:26 AM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int tcp_connect(const char *ip,int port)
{
	int fd_client = socket(AF_INET,SOCK_STREAM,0);
	if( -1 == fd_client )
		ERR_EXIT("socket error");
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);

	if( -1 == connect(fd_client,(struct sockaddr*)&server_addr,sizeof(struct sockaddr)))
		ERR_EXIT("connect error");
	return fd_client;

}

