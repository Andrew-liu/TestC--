/*************************************************************************
	> File Name: cl1.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 07:22:03 PM HKT
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
	int fd_wr = open("./1-2.fifo",O_WRONLY);
	printf("OK\n");
	int fd_rd = open("./2-1.fifo",O_RDONLY);
	printf("OK\n");
	int fd_wr_3 = open("./1-3.fifo",O_WRONLY);
	printf("OK\n");
	int fd_rd_3 = open("./3-1.fifo",O_RDONLY);
	printf("OK\n");
	printf("fd_wr %d\n",fd_wr);
	if ( (pid_1 = fork()) ==  0 )
	{
		close(fd_wr);
		while(memset(buf,0,1024),read(fd_rd,buf,1024)>0)
		{
			if( strcmp(buf,"bye")==0 )
			{
				break;
			}
			write(1,buf,strlen(buf));
		}

		close(fd_rd);
	}
	else if( (pid_2 = fork()) == 0 )
	{
			close(fd_wr_3);
			while(memset(buf,0,1024),read(fd_rd_3,buf,1024)>0 )
			{
				if( strcmp(buf,"bye") ==0)
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
			FILE *fp = fdopen(fd_wr,"w");
			FILE *fp_wr_3 = fdopen(fd_wr_3,"w");
			while(printf("su:"),memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL )
			{
				fprintf(fp,"%s",buf);
				fflush(fp);
				fprintf(fp_wr_3,"%s",buf);
				fflush(fp_wr_3);
			}
			fprintf(fp,"%s","bye");
			fprintf(fp_wr_3,"%s","bye");
			kill(pid_1,2);
			kill(pid_2,2);
			close(fd_wr);
			close(fd_wr_3);
			while(1);
		}
	return 0;
}

