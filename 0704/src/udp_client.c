/*************************************************************************
	> File Name: client.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:55:12 AM HKT
 ************************************************************************/

#include "UDP_socket.h"

int main(int argc,char *argv[])
{
	char send_buf[1024];
	char recv_buf[1024];
	struct sockaddr_in send_server,recv_client;
	int len_client;
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	int fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if( -1 == fd_socket )
	{
		perror("socket error\n");
		exit(-1);
	}
	bzero(&send_server,sizeof(send_server));
	send_server.sin_family = AF_INET;
	send_server.sin_port = htons(atoi(argv[2]));
	send_server.sin_addr.s_addr = inet_addr(argv[1]);
	while(1)//echo server
	{
		bzero(send_buf,1024);
		bzero(recv_buf,1024);
		bzero(&recv_client,sizeof(recv_client));
		fgets(send_buf,1024,stdin);
		send_buf[strlen(send_buf)-1] = '\0';

		sendto(fd_socket,send_buf,strlen(send_buf),0,(struct sockaddr*)&send_server,sizeof(send_server));
		len_client = 0;

		recvfrom(fd_socket,recv_buf,1024,0,(struct sockaddr *)&recv_client,&len_client);
		printf("The host %s:%d\tMsg: %s\n",inet_ntoa(recv_client.sin_addr),ntohs(recv_client.sin_port),recv_buf);
	}

}
