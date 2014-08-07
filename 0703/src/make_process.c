/*************************************************************************
	> File Name: make_process.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 08:53:12 PM HKT
 ************************************************************************/

#include "tcp_socket.h"

void make_process(pChild_info p,int num)
{
	int index;
	for(index = 0;index < num; ++index )
	{
		int fd1[2],fd2[2];//fd1[0]收管道儿子读端，fd1[1]收管道父亲写端，fd2[0]写管道儿子读端，fd2[1]写管道儿子写端
		pipe(fd1);
		pipe(fd2);
		pid_t s_pid = fork();
		if( 0 == s_pid )//son
		{
			close(fd1[1]);
			close(fd2[0]);
			dup2(fd1[0],0);
			dup2(fd2[1],1);
			close(fd1[0]);
			close(fd2[1]);
			child_main();
		}
		else
		{
			close(fd1[1]);
			close(fd2[0]);
			p[index].pid      = s_pid;
			p[index].status   = S_IDLE;
			p[index].fd_read  = fd1[0]; 
			p[index].fd_write = fd2[1];
			if(fds1[0] )
			p[index].s_cnt    = 0;

		}
	}
}


void child_main()
{
	int fd_client;
	int n;
	int status_over = 1;
	while(1)
	{
		n = scanf("%d",&fd_client);
		if( 1 == n)
		{
			handle_file(fd_client);
			printf("%d",status_over);
		}
	}
//	exit(-1);
}

