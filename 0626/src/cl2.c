/*************************************************************************
	> File Name: cl2.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 07:29:00 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
void my_hand(int num)
{
	wait(NULL);
	exit(1);
}
int main()
{
	int pid_1,pid_2;
	char buf[1024];
	int fd_rd = open("./1-2.fifo",O_RDONLY);
	printf("OB\n");
	int fd_wr = open("./2-1.fifo",O_WRONLY);
	printf("OB\n");
	int fd_wr_3 = open("./2-3.fifo",O_WRONLY);
	printf("OB\n");
	int fd_rd_3 = open("./3-2.fifo",O_RDONLY);
	printf("OB\n");
	printf("fd_rd %d\n",fd_rd);
//	FILE *fp_r = fdopen(fd_rd,"r");
	if( (pid_1=fork()) ==  0)
	{	
		close(fd_wr);
		while(memset(buf,0,1024),read(fd_rd,buf,1024)>0)
		{
			if( strcmp(buf,"bye") ==0 )
			{
				break;
			}
			write(1,buf,strlen(buf));
		}
		close(fd_rd);
	}
	else if( (pid_2=fork()) == 0 )
	{
		close(fd_wr_3);
		while(memset(buf,0,1024),read(fd_rd_3,buf,1024)>0)
		{
			if( strcmp(buf,"bye")==0)
			{
				break;
			}
			write(1,buf,strlen(buf));
		}
		close(fd_rd_3);
	}
	else
	{
		signal(17,my_hand);
		close(fd_rd);
		close(fd_rd_3);
		FILE *fp_wr = fdopen(fd_wr,"w");
		FILE * fp_wr_3 = fdopen(fd_wr_3,"w");
		while(printf("niubi:"),memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
		{
			fprintf(fp_wr,"%s",buf);
			fflush(fp_wr);
			fprintf(fp_wr_3,"%s",buf);
			fflush(fp_wr_3);
		}
		fprintf(fp_wr,"%s","bye");
		fprintf(fp_wr_3,"%s","bye");
			kill(pid_1,2);
			kill(pid_2,2);
			close(fd_wr_3);
			close(fd_wr);
			while(1);
	}
	return 0;
}
/*		if(fork()>0)
		{
			wait(NULL);
		}
		else//3->2 re
			{
				close(fd_wr_3);
				while(memset(buf,0,1024),read(fd_rd_3,buf,1024)>0)
				{
					write(1,buf,strlen(buf));
				}
				close(fd_rd_3);
			}*/
/*	else//re
	{
		close(fd_wr);
		while(memset(buf,0,1024),read(fd_rd,buf,1024)>0)
		{
			write(1,buf,strlen(buf));
		}
		close(fd_rd);
	}*/
//	return 0;
