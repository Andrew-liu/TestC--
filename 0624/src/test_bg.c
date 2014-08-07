/*************************************************************************
	> File Name: test_bg.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 10:41:05 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{
	while(1)
	{
		printf("pid = %d\n",getpid());
	}
	return 0;
}
