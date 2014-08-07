/*************************************************************************
	> File Name: my_server.c
	> Author: luoxin
	> Mail:17250308@qq.com 
	> Created Time: Wed 02 Jul 2014 04:48:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define SERVER_IP "192.168.1.69"
#define SERVER_PORT 8888
int main()
{
	int fd_server,fd_client;
	fd_server=socket(AF_INET,SOCK_STREAM,0);
	if(fd_server==-1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SERVER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SERVER_IP);
	if(bind(fd_server,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}
	if(listen(fd_server,5)==-1)
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}
	printf("begin accept!\n");
	int len=sizeof(client_addr);
	fd_client=accept(fd_server,(struct sockaddr*)&client_addr,&len);
	char buf[1024]="";
	while(1)
	{
		memset(buf,0,1024);
		int recv_n=recv(fd_client,buf,1024,0);
		printf("recv from IP:%s\nMsg:%s\nLen:%d\n",inet_ntoa(client_addr.sin_addr),buf,recv_n);
		int send_n=send(fd_client,buf,recv_n,0);
		printf("send to IP:%s\nMsg:%s\nLen:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),buf,send_n);
	}
	close(fd_server);
	close(fd_client);
	return 0;
}
