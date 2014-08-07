/*************************************************************************
	> File Name: getarray.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 17 Jun 2014 11:58:38 PM PDT
 ************************************************************************/

#include "func.h"

void getarray(int *a,int len)
{
	int i;
	srand(1);
	for (i=0; i<len;++i)
	{
		a[i] = rand()%100;
	}
}

