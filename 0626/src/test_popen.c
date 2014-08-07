/*************************************************************************
	> File Name: test_popen.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 09:25:15 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	FILE *fp;
	char buf[1024];
//	fp = popen("ls -l","r");
	fp = popen("./reserve_word","w");
	if( fp == NULL)
	{	
		perror("error\n");
		exit(-1);
	}
//	int ire =fread(buf,1,1024,fp);
	while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
	{
		if( buf[0] != '\n')
		{
			fprintf(fp,"%s\n",buf);
			fflush(fp);
		}

	}
//	printf("read from ppopen\n%s\n",buf);
	pclose(fp);

}

