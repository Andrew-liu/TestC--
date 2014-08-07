/*************************************************************************
	> File Name: test_copy_stat.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 07:54:28 PM PDT
 ************************************************************************/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	char buf[1024];
	int fd = open("/home/suqing/0620/bin/The_Holy_Bible.txt",O_RDONLY);
	int fd1 = dup(fd);
	read(fd,buf,4);
	puts(buf);
	close(fd);
	lseek(fd1,0,SEEK_SET);
	read(fd1,buf,sizeof(buf));
	puts(buf);
	close(fd1);
}
