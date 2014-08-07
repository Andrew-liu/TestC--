/*************************************************************************
	> File Name: test_getFileSize.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 08:37:56 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	int fo = open("./aaa.txt",O_RDONLY);
	struct stat buf;
	if( -1 == fo)
	{
		fprintf(stderr,"open failed\n");
		exit(-1);
	}
	fstat(fo,&buf);
	printf("The size is %d\n",buf.st_size);
}
