/*************************************************************************
	> File Name: test_gdb2.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 28 Jun 2014 04:01:49 PM HKT
 ************************************************************************/

#include <stdio.h>

int main()
{
	printf("core dump\n");
	*(char *)0 = 0;
	return 0;
}

