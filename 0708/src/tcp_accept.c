/*************************************************************************
	> File Name: tcp_accept.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 12:19:03 AM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int tcp_accept(int fd_server)
{
	struct sockaddr_in client_addr;
	memset(&client_addr,0,sizeof(client_addr));
	int len = sizeof(struct sockaddr);

	int fd_word_server = accept(fd_server,(struct sockaddr*)&client_addr,&len);
	if( -1 == fd_word_server )
		ERR_EXIT("accept error");
	printf("Client %s:%d success connect..\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	return fd_word_server;
}

