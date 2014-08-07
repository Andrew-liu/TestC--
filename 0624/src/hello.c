/*************************************************************************
	> File Name: hello.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 10:50:23 AM HKT
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
	int index;
	for( index = 0;index < argc; ++index)
	{
		printf("argc:%2d %10s\n",index,argv[index]);
	}
	return 0;
}

