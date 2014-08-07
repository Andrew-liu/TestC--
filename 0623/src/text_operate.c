/*************************************************************************
	> File Name: text_operate.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 04:56:02 PM HKT
 ************************************************************************/

#include "test.h"

int main(int argc,char *argv[])
{
	FILE *rd = fopen(filepath,"rb");
	if( rd == NULL)
	{
		perror("open error\n");
		exit(-1);
	}
	if( argc != 2)
	{
		perror("error,Please input \n");
		exit(-1);
	}
	else if( argc == 2)
	{
		init_txt(argv[1]);
		
	}

}
