/*************************************************************************
	> File Name: client.c
	> Author: tanjx923
	> Mail:jas.firefly@hotmail.com 
	> Created Time: Wed 02 Jul 2014 04:57:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERVER_IP "192.168.1.68"
#define SERVER_PORT 8888

int main()
{
	//socket
	int fd_client;
	fd_client=socket(AF_INET,SOCK_STREAM,0);
	if(fd_client==-1)
	{
		perror("socket error!\n");
		exit(-1);
	}
	//
	//************************************
	//connect
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SERVER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SERVER_IP);

	if( connect(fd_client,(struct sockaddr*)&server_addr,sizeof(struct sockaddr))==-1)
	{
		perror("connect error!\n");
		close(fd_client);
		exit(-1);
	}
	//
	//**********************************
	//send&recv
	char send_buf[1024]="";
	char recv_buf[1024]="";
	while(memset(send_buf,0,1024),fgets(send_buf,1024,stdin)!=NULL)
	{
		int send_n=send(fd_client,send_buf,strlen(send_buf),0);
		//printf("send to IP:%s\nMessage:%s\nLen:%d\n",inet_ntoa(server_addr.sin_addr),send_buf,send_n);
		while(memset(recv_buf,0,1024),recv(fd_client,recv_buf,1024,0)>0)
		{
			if(strncmp(recv_buf,"bye",3)==0)
				break;
			printf("%s\n",recv_buf);
		//printf("recv from IP:%s\nMessage:%s\nLen:%d\n",inet_ntoa(server_addr.sin_addr),recv_buf,recv_n);
		}
	}
	strcpy(send_buf,"bye");
	send(fd_client,send_buf,strlen(send_buf),0);
	//
	//***********************************
	//close
	sleep(1);
	close(fd_client);
	return 0;
}
