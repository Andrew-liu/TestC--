/*************************************************************************
	> File Name: test_dup.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 20 Jun 2014 05:07:58 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char s[100];
	int fd = open("/home/suqing/0620/bin/Nolook.txt",O_WRONLY | O_CREAT,0755);
//	int fd = open("/home/suqing/0620/bin/test_dup.txt",0755);
	if( -1 == fd) 
	{
		fprintf(stderr,"open fail\n");
		exit(-1);
	}
	printf("input Yes\n");
	scanf("%s",s);
	printf("what a hot day!\n");
//	fprintf(stderr,"What a hot day\n");
	getchar();//实现刷新
	scanf("%s",s);
	close(1);//关闭标准输出
	int fd2 = dup(fd);//实现输出的重定向
	printf("what a hot day!\n");
	close(fd2);
	return 0;
}

