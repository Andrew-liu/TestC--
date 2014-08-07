/*************************************************************************
	> File Name: make_process.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 08 Jul 2014 03:05:49 PM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int make_process(pChild_info p, int num)
{

	int index,max_read = -1;
	pid_t pid;
	for( index=0; index < num; ++index )
	{
		int fd[2];//0 read 1 write
		if( -1 == socketpair(AF_LOCAL,SOCK_STREAM,0,fd) )
			ERR_EXIT("socketpair error");
		pid = fork();
		if( 0 == pid )
		{
	//			dup2(fd[0],0);
	//			dup2(fd[1],1);
			int work_socket;
			int status_over = 0;
			while(1)
			{
				close(fd[1]);
				recv_describe(fd[0],&work_socket);
				handle_requst(work_socket);
				write(fd[1],&status_over,sizeof(int));	
			}
			//	child_main();
		}
		else
		{
		//	signal(SIGCHLD,recy_source);
			p[index].pid = pid;
			p[index].status   = S_IDLE;
			p[index].fd_read  = fd[0];
			if( max_read < p[index].fd_read )
				max_read = p[index].fd_read;
			p[index].fd_write = fd[1];
			p[index].count = 0;
		}
	}
	return max_read;
}
/*void child_main()
{
	int work_socket;
	int status_over = 0;
	while(1)
	{
		recv_describe(fd[0],&work_socket);
		printf("BBBB\n");
		handle_requst(work_socket);
		write(fd[1],&status_over,sizeof(int));

		//printf("%d",status_over);
	}
}*/
void handle_requst(int fd_client)
{
	char recv_buf[1024];
	int len;
	while(1)
	{
		bzero(recv_buf,1024);
		recv(fd_client,&len,sizeof(int),0);
		if( 0 == len )
			break;
		else
		{
			recv(fd_client,recv_buf,len,0);
			printf("From Client %s\n",recv_buf);
			send(fd_client,&len,sizeof(int),0);
			send(fd_client,recv_buf,len,0);
		}
	}
}
