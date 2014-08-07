/*************************************************************************
	> File Name: client_socket.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 07:31:25 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_IP "192.168.1.25"
#define SERVER_PORT 8888 

int main()
{
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));

	int fd_client = socket(AF_INET,SOCK_STREAM,0);
	if( -1== fd_client )
	{
		perror("socket error\n");
		exit(-1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	connect(fd_client,(struct sockaddr*)&server_addr,sizeof(server_addr));
	printf("connecting!\n");
	
	char send_buf[1024];
	while( memset(send_buf,0,1024),fgets(send_buf,1024,stdin)!=NULL && send_buf[0] != '\n' )
	{
		char recv_buf[1024];
		send_buf[strlen(send_buf)-1] = '\0';
		printf("send message %s\n",send_buf);
		send(fd_client,send_buf,strlen(send_buf),0);
		recv(fd_client,recv_buf,1024,0);
		printf("recv from ip:port%s:%d\nMsg:%s\n",inet_ntoa(server_addr.sin_addr),ntohs(server_addr.sin_port),recv_buf);
	}
	close(fd_client);

}
