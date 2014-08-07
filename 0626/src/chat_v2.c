/*************************************************************************
	> File Name: chat_v2.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 03:36:14 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char buf[1024];
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	if( fork()>0 )//parent
	{
		close(fd1[1]);
		close(fd2[0]);
		while(memset(buf,0,1024),read(fd1[0],buf,1024) >0 )//parent read
		{
			write(1,buf,strlen(buf));
		}
		close(fd1[0]);
//		wait(NULL);
		FILE *fp_p = fdopen(fd2[1],"w");
		while( memset(buf,0,1024),fgets(buf,1024,stdin) != NULL)//parent write
		{
			fprintf(fp_p,"from parent %s",buf);
			fflush(fp_p);
		}
		close(fd2[1]);
		wait(NULL);
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);
		FILE *fp_k = fdopen(fd1[1],"w");
		while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)//kid write
		{
			fprintf(fp_k,"from kid:%s",buf);
			fflush(fp_k);
		}
		close(fd1[1]);
		while(memset(buf,0,1024),read(fd2[0],buf,1024) > 0 )//kid read
		{
			write(1,buf,strlen(buf));
		}
		close(fd2[0]);
	}
}

