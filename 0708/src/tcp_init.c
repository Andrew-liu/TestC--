/*************************************************************************
	> File Name: tcp_init.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 12:03:13 AM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int tcp_init(const char *ip,int port)
{
	int reuse = 1;
	int fd_server = socket(AF_INET,SOCK_STREAM,0);
	if( -1 == fd_server )
		ERR_EXIT("socket error");
	if( 0 != setsockopt(fd_server,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)))
		ERR_EXIT("setport error");
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);

	if( -1== bind(fd_server,(struct sockaddr*)&server_addr,sizeof(server_addr)) )
	ERR_EXIT("bind error");

	if( -1 == listen(fd_server,5) )
		ERR_EXIT("listen error");

	return fd_server;
}
