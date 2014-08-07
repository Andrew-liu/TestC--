/*************************************************************************
	> File Name: test_read.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 11:50:56 PM HKT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char buf[1024];
	int nread;
	int fd = open(argv[1],O_RDONLY);
	while(memset(buf,0,1024),( nread = read(fd,buf,1024)) >0 )
	{
	//	puts(buf);
//		printf("%s\n",buf);
		write(1,buf,strlen(buf));
	}
	printf("%d\n",nread);
	return 0;
}
