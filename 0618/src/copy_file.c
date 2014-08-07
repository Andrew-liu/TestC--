/*************************************************************************
	> File Name: copy_file.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 07:12:53 AM PDT
 
	*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define filename1 "./aaa.txt"
#define filename2 "./bbb.txt"
int main()
{
	char buf[1024];
	int fo1 = open(filename1,O_RDONLY);
	int fo2 = creat(filename2,0755);
	int fr;
	if((-1==fo1) || (-1==fo2))
	{
		perror("open fail\n");
		exit(-1);
	}
	while((fr= read(fo1,buf,sizeof(buf)))>0)
	{
		int fw = write(fo2,buf,fr);
		if(-1 == fw)
		{
			perror("write failed\n");
			exit(-1);
		}
	}
	close(fo1);
	close(fo2);
}

