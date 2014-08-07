/*************************************************************************
	> File Name: test_gdb.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 28 Jun 2014 03:31:02 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int fun(int a)
{
	int i,sum = 0;
	for( i=0;i<=a;++i)
	{
		sum += i;
	}
	return sum;
}
int main()
{
	int i = 0;
	int a = 10;
	int s = fun(a);
	printf("sum is %d\n",s);
	return 0;
	
}

