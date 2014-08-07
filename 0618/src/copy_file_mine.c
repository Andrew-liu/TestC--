/*************************************************************************
	> File Name: copy_file_mine.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 07:36:14 AM PDT
 ************************************************************************/
#include <unistd.h> //文件描述符的各类系统调用
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>//perror的头文件
#include <stdlib.h>
#define filename1 "./aaa"
#define filename2 "./bbb"//用于写，一开始不存在
int main()
{
	char buf[1024];
	int fo1 = open(filename1,O_RDONLY);
	int fo2 = open(filename2,O_CREAT|O_WRONLY);
	int fr,fw;//用于记录读写返回的个数 
	if((-1==fo1)|| (-1==fo2))
	{
		perror("open failed\n");
		exit(-1);
	}
	while((fr = read(fo1,buf,sizeof(buf)))>0)
	{
		fw = write(fo2,buf,fr);
		if( -1==fw)
		{
			perror("write failed\n");
			exit(-1);
		}
	}
	close(fo1);
	close(fo2);
}


