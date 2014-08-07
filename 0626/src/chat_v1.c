/*************************************************************************
	> File Name: chat_v1.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 02:55:37 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
/*
 * 1.开辟缓冲区
 * 2.初始化读写管道，必须在fork前
 * 3.利用fdopen得到读写管道的文件描述符
 *
 */
int main()
{
	char buf[1024];
	int fd[2];
	pipe(fd);
	if( fork() >0 )
	{
		close(fd[1]);
		while( read(fd[0],buf,1024) > 0 )
		{
			write(1,buf,strlen(buf));
		}
		close(fd[0]);
		wait(NULL);
	}else
	{
		close(fd[0]);
		FILE *fp = fdopen(fd[1],"w");
		while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
		{
			buf[strlen(buf)-1] = '\0';
			fprintf(fp,"%s\n",buf);
			fflush(fp);
		}
		close(fd[1]);

	}
}
