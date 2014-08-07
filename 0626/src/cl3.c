/*************************************************************************
	> File Name: cl3.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 08:57:06 PM HKT
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
	int fd_rd_1 = open("./1-3.fifo",O_RDONLY);
	printf("OL\n");
	int fd_wr_1 = open("./3-1.fifo",O_WRONLY);
	printf("OL\n");
	int fd_rd_2 = open("./2-3.fifo",O_RDONLY);
	printf("OL\n");
	int fd_wr_2 = open("./3-2.fifo",O_WRONLY);
	printf("OL\n");

	if( (pid_1 = fork()) == 0)//3->1 send
	{
		close(fd_wr_1);
		while(memset(buf,0,1024),read(fd_rd_1,buf,1024)>0 )
			{
				if(strcmp(buf,"bye")==0)
				{
					break;
				}
				write(1,buf,strlen(buf));
			}
		close(fd_rd_1);
	}
	else if( (pid_2 = fork()) ==0 )
	{
		close(fd_wr_2);
		while(memset(buf,0,1024),read(fd_rd_2,buf,1024)>0)
		{
			if( strcmp(buf,"bye")==0)
			{
				break;
			}
			write(1,buf,strlen(buf));
		}
		close(fd_rd_2);

	}
	else
	{
		signal(17,my_hand);
		close(fd_rd_1);
		close(fd_rd_2);
		FILE *fp_wr_1 = fdopen(fd_wr_1,"w");
		FILE *fp_wr_2 = fdopen(fd_wr_2,"w");
		while(printf("luoxin: "),memset(buf,0,1024),fgets(buf,1024,stdin)!= NULL)
		{
			fprintf(fp_wr_1,"%s",buf);
			fflush(fp_wr_1);
			fprintf(fp_wr_2,"%s",buf);
			fflush(fp_wr_2);
		}
		fprintf(fp_wr_1,"%s","bye");
		fprintf(fp_wr_2,"%s","bye");
		kill(pid_1,2);
		kill(pid_2,2);
		close(fd_wr_1);
		close(fd_wr_2);
		while(1);
	}
	wait(NULL);
}
