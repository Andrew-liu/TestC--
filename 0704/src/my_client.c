/*************************************************************************
	> File Name: my_client.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:52:45 PM HKT
 ************************************************************************/

#include "chat_muti.h"
/*
 * 1.客户端单聊:
 *
 *
 * 2.客户端群聊:
 *
 *
 *
 */
void *my_recv(void *arg)
{
	pthread_detach(pthread_self());
	int fd_client1 = (int)arg;
	char recv_buf[1024];
	int len = sizeof(SA);
	SA obj_addr;
	bzero(&obj_addr,sizeof(SA));
	while(1)
	{
		bzero(recv_buf,1024);
//		bzero(&obj_addr,sizeof(SA));
		recvfrom(fd_client1,recv_buf,1024,0,(struct sockaddr*)&obj_addr,&len);
	//	printf("AAAa\n");
		printf("From %s Msg %s\n",inet_ntoa(obj_addr.sin_addr),recv_buf);
	}

}

void signal_chat(int fd_client,MSG *msg,SA *addr);
void muti_chat(int fd_client,MSG *msg_grp,SA *addr);

int main(int argc,char *argv[])
{

	char opt;
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

	//init message
	MSG msg_on,msg_off,msg_usr,msg_grp;
	bzero(&msg_off,sizeof(MSG));
	//init connect info
	SA server_addr;
	bzero(&server_addr,sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	//client logon,send to server
	bzero(&msg_on,sizeof(MSG));
	msg_on.s_type = MSG_ON;
	sendto(fd_client,&msg_on,sizeof(MSG),0,(struct sockaddr*)&server_addr,sizeof(SA));
	//rec use pthread
	pthread_t tid;
	pthread_create(&tid,NULL,my_recv,(void *)fd_client);
	//select ways to chat
	printf("The way you want to chat:\n");
	printf("1.signal  chat\n");
	printf("2.mutiple chat\n");
	scanf("%c",&opt);
	switch(opt)
	{
		case '1':
			getchar();
			signal_chat(fd_client,&msg_usr,&server_addr);
			break;
		case '2':
			getchar();
			muti_chat(fd_client,&msg_grp,&server_addr);
			break;
	}

	//off
	bzero(&msg_off,sizeof(MSG));
	msg_off.s_type = MSG_OFF;
	sendto(fd_client,&msg_off,sizeof(MSG),0,(struct sockaddr*)&server_addr,sizeof(SA));
	close(fd_client);

}

void signal_chat(int fd_client,MSG *msg,SA *addr)
{
//	SA obj_addr;
	char getip[32];
	int port = 8888;
	
//	pthread_t tid;
//	pthread_create(&tid,NULL,my_recv,(void *)fd_client);
	while(1)
	{
		pthread_t tid;
		pthread_create(&tid,NULL,recv_online,(void *)fd_client);

		bzero(msg,sizeof(MSG));
		printf("input the ip you want to chat\n");
		fgets(getip,32,stdin);
		getip[strlen(getip)-1] = '\0';
		if( is_ip(getip) == -1 )
			continue;
		msg->s_addr.sin_family = AF_INET;
		msg->s_addr.sin_port   = htons(port);
		msg->s_addr.sin_addr.s_addr = inet_addr(getip);
		while(bzero((msg->s_msg),1024),fgets((msg->s_msg),MSG_SIZE,stdin)!=NULL)
		{
			msg->s_msg[strlen(msg->s_msg)-1] = '\0';
			msg->s_type = MSG_USR;
			msg->s_len  = strlen(msg->s_msg);
			sendto(fd_client,msg,sizeof(MSG),0,(struct sockaddr*)addr,sizeof(SA));
		}
	}
}
void muti_chat(int fd_client,MSG *msg_grp,SA *addr)
{
//	pthread_t tid;
//	pthread_create(&tid,NULL,my_recv,(void *)fd_client);
	while( bzero(msg_grp,sizeof(MSG)),fgets(msg_grp->s_msg,MSG_SIZE,stdin)!=NULL)
	{
		msg_grp->s_msg[strlen(msg_grp->s_msg)-1] = '\0';
		msg_grp->s_type = MSG_GRP;
		msg_grp->s_len  = strlen(msg_grp->s_msg);
		sendto(fd_client,msg_grp,sizeof(MSG),0,(struct sockaddr*)addr,sizeof(SA));
	}
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
