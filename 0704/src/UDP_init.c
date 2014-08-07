/*************************************************************************
	> File Name: UDP_init.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:40:02 AM HKT
 ************************************************************************/

#include "UDP_socket.h"

int udp_init(const char *ip,int port)
{
	int fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if( -1 == fd_socket )
	{
		perror("socket error\n");
		exit(-1);
	}
	struct sockaddr_in sock_addr;
	bzero(&sock_addr,sizeof(sock_addr));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port   = htons(port);
	sock_addr.sin_addr.s_addr = inet_addr(ip);
	
	if( -1 == bind(fd_socket,(struct sockaddr*)&sock_addr,sizeof(sock_addr)))
	{
		perror("bind error\n");
		exit(-1);
	}
	return fd_socket;
}
