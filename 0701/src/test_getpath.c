/*************************************************************************
	> File Name: test_getpath.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 01 Jul 2014 07:42:53 PM HKT
 ************************************************************************/

#include<stdio.h>
#include <string.h>

void get_path(char *str)
{
	char buf[32];
	memset(buf,0,32);
	int pos = 0;
	while(sscanf(str+pos,"%s",buf)==1)
	{
		puts(buf);
		pos = pos + strlen(buf)+1;
	}
	puts("---");
	puts(buf);
	strcpy(str,buf);
}

int main()
{
	char buf[1014] = "1234 jidfdf";
	puts(buf);
	get_path(buf);
//	fprintf(stdout,"from client:%d,want read %s\n",buf);
	puts(buf);
	return 0;
}
