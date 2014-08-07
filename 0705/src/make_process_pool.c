/*************************************************************************
  > File Name: make_process_pool.c
  > Author: Suqing
  > Mail:116676671@qq.com 
  > Created Time: Sat 05 Jul 2014 03:35:34 PM HKT
 ************************************************************************/

#include "udp_process_pool.h"

int make_process_pool(int num,pChild p)
{
	int max_read = 0;
	int index;
	printf("DDDD\n");
	for( index=0;index < num;++index )
	{
		pid_t pid;
		int fd1[2],fd2[2];//fd1[0]->pr,fd1[1]->cw,fd2[0]->cr,fd2[1]->pw
		pipe(fd1);
		pipe(fd2);
		pid = fork();
		//child
		if( 0 == pid )
		{
			printf("MMM\n");
			close(fd1[0]);
			close(fd2[1]);
			dup2(fd2[0],0);
			dup2(fd1[1],1);
		//	close(fd2[0]);
		//	close(fd1[1]);
			child_main();
			exit(-1);

		}
		//parent use for init child struct
		else
		{
			printf("GGGG\n");
			close(fd1[1]);
			close(fd2[0]);
			p[index].pid  = pid;
			p[index].flag = S_IDLE;
			p[index].fd_read  = fd1[0];
			if( fd1[0] > max_read )
			{
				max_read = fd1[0];
			}
			printf("%d\n",fd2[1]);
			p[index].fd_write = fd2[1];
			p[index].cnt = 0;

		}
	}
	return max_read;
}
void child_main()
{
	char over_flag = '1';
	SA client_addr;
	char recv_buf[128];
	int fd_socket;
	char ip[32]="";
	int port;
	fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	while(1)
	{	
		bzero(&client_addr,sizeof(SA));
		bzero(recv_buf,128);
		client_addr.sin_family = AF_INET;
		scanf("%s%d%s",ip,&port,recv_buf);
		client_addr.sin_port = htons(port);
		client_addr.sin_addr.s_addr = inet_addr(ip);
		if( -1 == fd_socket )
		{
			perror("socket error\n");
			exit(-1);
		}
		my_handle(fd_socket,&client_addr,recv_buf);
		printf("1");
		fflush(stdout);
	}
}

void my_handle(int fd_client,SA *addr,char *send_buf)
{
	sendto(fd_client,send_buf,strlen(send_buf),0,(struct sockaddr*)addr,sizeof(SA));
}

