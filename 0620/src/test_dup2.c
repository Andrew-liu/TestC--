/*************************************************************************
	> File Name: test_dup2.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 20 Jun 2014 05:50:21 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int fd1 = open("/home/suqing/0620/bin/test_dup2.txt",O_RDONLY | O_CREAT);
	int fd2 = open("/home/suqing/0620/bin/test_dup22.txt",O_RDONLY | O_CREAT);
	if( -1 ==fd1 || -1 == fd2 )
	{
		perror("open error\n");
		exit(-1);
	}
	int fd3 = dup

}

