/*************************************************************************
	> File Name: mv_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 02:28:12 PM HKT
 ************************************************************************/

#include "mv.h"
int main( int argc,char *argv[])
{
	if( argc < 2)
	{
		perror("error\n");
		exit(-1);
	}
	else
	{
		my_mv(argv[1],argv[2]);
	}
	return 0;
}

