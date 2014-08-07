/*************************************************************************
	> File Name: my_popen.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 04:06:15 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int command(char *com);
FILE *my_popen(char *com)
{
	int fd[2];
	char buf[1024];
	char **list;
	command(com,list);
	pipe(fd);
	if( fork()>0 )//parent read
	{
		close(fd[1]);
		while( memset(buf,0,1024),read(fd[0]))
		wait(NULL);
	}
	else//kid write
	{
		close(fd[1]);
		FILE *fp = fdopen(fd[1],"w");
		dup2(fd[0],1);
		execvp(list[0],list);
		fprintf(fp,"%s",buf)

	}

}


int command(char *com,char **list)
{
	char buf[32];
	int pos=0,i=0;
	int count = 0;
	while( sscanf(com+pos,"%s",buf)==1 )
	{
		++count;
		pos = pos + strlen(buf)+1;
	}
	list = (char **)malloc( (count+1)*sizeof(char *));
	while( sscanf(com+pos,"s",list[i]) == 1)
	{
		++i;
	}
	strcpy(list[i], NULL);
	return count;
}
