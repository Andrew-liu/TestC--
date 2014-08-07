/*************************************************************************
	> File Name: udp_1.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:55:12 AM HKT
 ************************************************************************/

#include "UDP_socket.h"
void *my_recv(void *arg)
{
	pthread_detach(pthread_self());
	int fd_socket = (int)arg;
	char buf[1024];
//	int len_client=sizeof(recv_server);
	struct sockaddr_in recv_server;
	int len_client=sizeof(recv_server);
	while(1)
	{
		bzero(&recv_server,sizeof(recv_server));
		bzero(buf,1024);
		recvfrom(fd_socket,buf,1024,0,(struct sockaddr *)&recv_server,&len_client);
		if( strncmp(buf,"bye",3) == 0 )
		{
			break;
		}
		printf("FROM:%s Msg: %s\n",inet_ntoa(recv_server.sin_addr),buf);
	}

}

int main(int argc,char *argv[])
{
	char recv_buf[1024];
	char send_buf[1024];
	char chat_ip[32];
	int chat_port = atoi(argv[2]);
	struct sockaddr_in send_client;
	int len_client;
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	int fd_socket = udp_init(argv[1],atoi(argv[2]));

	while(printf("ip: "),fflush(stdout),bzero(chat_ip,32),fgets(chat_ip,32,stdin)!=NULL)
	{
		if(chat_ip[0] == '\n')
			continue;
		if( -1 == is_ip(chat_ip) )
			continue;
		printf("OK\n");	

		bzero(&send_client,sizeof(send_client));
		send_client.sin_family = AF_INET;
		send_client.sin_port   = htons(chat_port);
		chat_ip[strlen(chat_ip)-1] = '\0';
		send_client.sin_addr.s_addr = inet_addr(chat_ip);

		pthread_t tid;
		pthread_create(&tid,NULL,my_recv,(void *)fd_socket);
		printf("OK\n");

		while(bzero(send_buf,1024),fgets(send_buf,1024,stdin)!=NULL)
		{
			send_buf[strlen(send_buf)-1] = '\0';
			sendto(fd_socket,send_buf,strlen(send_buf),0,(struct sockaddr*)&send_client,sizeof(send_client));
		}
		sendto(fd_socket,"bye",3,0,(struct sockaddr*)&send_client,sizeof(send_client));
		
	}
	return 0;
}

int is_ip(char *ip)//0 is right
{
	int ips[4];
	if( 4 != sscanf(ip,"%d.%d.%d.%d",&ips[0],&ips[1],&ips[2],&ips[3]))
	{
		printf("ip format error\n");
		return -1;
	}
	else
	{
		if( ips[0]>255 || ips[1]>255 || ips[2]>255 ||ips[3]>255 )
		{
			printf("ip error\n");
			return -1;
		}
		else
			return 0;
	}
}
