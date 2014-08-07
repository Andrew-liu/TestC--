/*************************************************************************
	> File Name: tcp_init.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 12:03:13 AM HKT
 ************************************************************************/

#include "tcp_socket.h"

int tcp_init()
{
	int reuse = 1;
	int fd_server = socket(AF_INET,SOCK_STREAM,0);
	if( -1 == fd_server )
	{
		perror("socket error\n");
		close(fd_server);
		exit(-1);
	}
	if( 0 != setsockopt(fd_server,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)))
	{
		perror("set error\n");
		exit(-1);
	}
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	if( -1== bind(fd_server,(struct sockaddr*)&server_addr,sizeof(server_addr)) )
	{
		perror("bind error\n");
		close(fd_server);
		exit(-1);
	}

	if( -1 == listen(fd_server,5) )
	{		perror("listen error\n");
		close(fd_server);
		exit(-1);
	}

	return fd_server;
}
/*
int main()
{
	return 0;
}*/

