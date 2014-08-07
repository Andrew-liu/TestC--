/*************************************************************************
	> File Name: test.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 07 Jul 2014 01:15:15 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char buf[1024] = "";
	int len =0;
	int fd = open("The_Holy_Bible.txt",O_RDONLY);
	while(memset(buf,0,1024),read(fd,buf,1024)>0 ) 
	{
		printf("len = %d\n",strlen(buf));
	}
		printf("OK\n");
}
