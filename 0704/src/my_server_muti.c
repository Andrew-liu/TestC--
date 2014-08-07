/*************************************************************************
	> File Name: my_server_muti.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 08:51:07 PM HKT
 ************************************************************************/

#include "chat_muti.h"

int main(int argc,char*argv[])
{
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	//init socket
	int fd_server = udp_init(argv[1],atoi(argv[2]));
	//init client table
	pUSR client_table;
	LinkList_init(&client_table);
	//init struct msg
	MSG client_msg;
	bzero(&client_msg,sizeof(MSG));
	//init select
	fd_set read_set,ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd_server,&read_set);
	struct timeval t;

	//start select
	while(1)
	{
		t.tv_sec  = 0;
		t.tv_usec = 1000;
		ready_set = read_set;
		if( -1 == select(fd_server+1,&ready_set,NULL,NULL,&t) )
		{
			perror("selcet error\n");
			exit(-1);
		}
		//select handle
		if( FD_ISSET(fd_server,&ready_set) )
		{			//recv msg from client,and select the way to handle
			SA client_addr;
		//	bzero(&client_addr,sizeof(SA));
			MSG client_msg;
			bzero(&client_msg,sizeof(MSG));
			int len_client_addr = sizeof(SA);
			recvfrom(fd_server,&client_msg,sizeof(MSG),0,(struct sockaddr*)&client_addr,&len_client_addr);
			printf("The type is %d\n",client_msg.s_type);
			//choice a way to handle
			switch(client_msg.s_type)
			{
				case MSG_USR:
					msg_usr(fd_server,&client_msg);
					break;
				case MSG_GRP:
					msg_grp(client_table,fd_server,&client_msg);
					break;
				case MSG_ON:
					msg_on(&client_table,&client_addr);
					break;
				case MSG_OFF:
					msg_off(&client_table,&client_addr);
					break;
			}
		}
	}
	
}

void LinkList_init(pUSR *p)
{
	(*p) = (pUSR)calloc(1,sizeof(USR));
}
void msg_on(pUSR *p,SA *addr)
{
	FILE *fp = fopen("a.txt","a");
	printf("Client %s:%d is online..\n",inet_ntoa(addr->sin_addr),ntohs(addr->sin_port));
	pUSR new_client = (USR *)calloc(1,sizeof(USR));
	new_client->s_addr = *addr;
	fprintf(fp,"%s %d\n",inet_ntoa(addr->sin_addr),ntohs(addr->sin_port));
	fflush(fp);
	sendto(fd_server,);
	new_client->next = (*p)->next;
	(*p)->next = new_client;
	fclose(fp);
}
void msg_off( pUSR *p,SA *addr )
{
	pUSR pre ,cur;
	pre = *p;
	cur = pre->next;
	while( cur )
	{
		if( cur->s_addr.sin_addr.s_addr  == addr->sin_addr.s_addr )
			break;
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	if( NULL == cur )
		printf("sorry,can't find the client\n");
	else
	{
		pre->next = cur->next;
		free(cur);
	}
}
void msg_usr(int fd_server,MSG *msg)
{
	printf("OK\n");
	printf("msg %s len = %d\n",msg->s_msg,msg->s_len);
	printf("From %s:%d\n",inet_ntoa(msg->s_addr.sin_addr),ntohs(msg->s_addr.sin_port));
	sendto(fd_server,msg->s_msg,msg->s_len,0,(struct sockaddr*)&(msg->s_addr),sizeof(SA));
//	sendto(fd_server,msg,msg->s_len,0,(struct sockaddr*)&(msg->s_addr),sizeof(SA));
}
void msg_grp(pUSR p,int fd_server,MSG *msg)
{
	pUSR cur = p->next;
	while( cur )
	{
		sendto(fd_server,msg->s_msg,msg->s_len,0,(struct sockaddr*)&(cur->s_addr),sizeof(SA));
		cur = cur->next;
	}
}

