/*************************************************************************
	> File Name: client_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 05 Jul 2014 08:10:15 PM HKT
 ************************************************************************/

#include "udp_process_pool.h"

void *my_recv(void *arg)
{
	int fd_client = (int)arg;
	SA from_server;
	int len = sizeof(SA);
	char recv_buf[1024];
	while(1)
	{
		printf("VBBBBB\n");
		bzero(&from_server,sizeof(SA));
		bzero(recv_buf,1024);
		recvfrom(fd_client,recv_buf,1024,0,(struct sockaddr*)&from_server,&len);
		printf("FROM %s:%d Msg %s\n",inet_ntoa(from_server.sin_addr),ntohs(from_server.sin_port),recv_buf);
	}
}

int main(int argc,char *argv[])//exe,ip,port
{
	char send_buf[1024];
	char recv_buf[1024];
	int len = sizeof(SA);
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	//init client socket
	int fd_client = socket(AF_INET,SOCK_DGRAM,0);
	if( -1 == fd_client )
	{
		perror("socket error\n");
		exit(-1);
	}
	//init SA struct
	SA sent_server,from_server;
	bzero(&sent_server,sizeof(SA));
	sent_server.sin_family = AF_INET;
	sent_server.sin_port   = htons(atoi(argv[2]));
	sent_server.sin_addr.s_addr = inet_addr(argv[1]);
		
//	pthread_t tid;
//	pthread_create(&tid,NULL,my_recv,(void *)fd_client);
	//send message to server
	while(printf("input\n"),fgets(send_buf,1024,stdin)!=NULL)
	{
		sendto(fd_client,send_buf,strlen(send_buf),0,(struct sockaddr*)&sent_server,sizeof(SA));
		bzero(recv_buf,1024);
		bzero(&from_server,sizeof(SA));
		recvfrom(fd_client,recv_buf,1024,0,(struct sockaddr*)&from_server,&len);
		printf("FROM %s:%d Msg %s\n",inet_ntoa(from_server.sin_addr),ntohs(from_server.sin_port),recv_buf);
		printf("OK\n");
	}
	//create thread to recv


}

