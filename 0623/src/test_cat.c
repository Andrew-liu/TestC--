/*************************************************************************
	> File Name: test_cat.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 09:41:25 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define filename "./cat.txt"
int main(int argc,char *argv[])
{
	int fd;
	int iret;
	int i;
	char buf[1024];
//	int fdw  = open(filename,O_WRONLY | O_CREAT);
	if(argc < 2)
	{
		while(memset(buf,0,1024),read(STDIN_FILENO,buf,sizeof(buf)))//read会读取'\n'
		{
			write(STDOUT_FILENO,buf,strlen(buf));
		}

	}
	else
	{
		for(i=0;i<argc;++i)
		{
			fd = open(argv[i],O_RDONLY);
			if(-1 == fd)
			{
				perror("open error\n");
				exit(-1);
			}	
			while(memset(buf,0,1024),read(fd,buf,sizeof(buf)))//read会读取'\n'
			{
				write(STDOUT_FILENO,buf,strlen(buf));
			}
			close(fd);
		}
	}
}


