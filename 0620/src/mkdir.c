/*************************************************************************
	> File Name: mkdir.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:38:31 PM PDT
 ************************************************************************/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	if( argc < 2)
	{
		fprintf(stderr,"error\n");
		exit(-1);
	}
	else
	{
		mkdir(argv[1],0777);
	}
	return 0;
}


