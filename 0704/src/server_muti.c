/*************************************************************************
	> File Name: server_muti.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 05:05:46 PM HKT
 ************************************************************************/

#include "chat_muti.h"

void init_LinkList(pUSR *L)
{
	(*L)  = (pUSR)calloc(1,sizeof(USR));
}
void inerst_head(pUSR *L,SA *addr)
{
	pUSR new_usr = (USR *)calloc(1,sizeof(USR));
	new_usr->s_addr = *addr;
	new_usr->next = (*L)->next;
	(*L)->next = new_usr;

}
void delete_LinkList(pUSR *L,SA *addr)
{

}
void travel_LinkList(pUSR L,(void*)(*handle)() )
{

}



int main(int argc,char *argv[])
{
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	//init socket
	int fd_server = udp_init(argv[1],atoi(argv[2]));

	//init LinkList
	pUSR L;
	init_LinkList(&L);
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
			perror("select error\n");
			exit(-1);
		}
		if(FD_ISSET(fd_server,&ready_set))
		{
			SA client_info;
			MSG chat_msg;
			int client_len = sizeof(SA);
			recvfrom(fd_server,&chat_msg,sizeof(MSG),(struct sockaddr*)&client_info,&client_len);
			switch(chat_msg.s_type)
			{
				case 1:
					mse_usr();
					break;
				case 2:
					mse_grp();
					break;
				case 3:
					mse_on();
					break;
				case 4:
					mse_off();
					break;
			}
		}

	}




}

