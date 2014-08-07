/*************************************************************************
	> File Name: print.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 12:01:58 AM PDT
 ************************************************************************/

#include "func.h"

void print(const char *str,int *a,int len)
{
	int i;
	printf("%s\n",str);
	for (i=0; i<len; ++i)
		printf(" %d ",a[i]);
	printf("\n");
}
