/*************************************************************************
	> File Name: test_ppopen.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 24 Jun 2014 11:35:37 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define command "top"
int main()
{
	FILE *p_read;
	char buf[1024];
	p_read = popen(command,"r");
	if(p_read == NULL)
	{
		perror("read error\n");
		exit(-1);
	}
	else
	{
	//	memset(buf,0,1024);
		while(memset(buf,0,1024), fread(buf,sizeof(char),1024,p_read) )
		{
			puts(buf);

		}
	//	puts(buf);
	}
	pclose(p_read);
	return 0;
}
