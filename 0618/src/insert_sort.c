/*************************************************************************
	> File Name: insert_sort.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 17 Jun 2014 11:47:41 PM PDT
 ************************************************************************/

#include "func.h"
void insert_sort(int *a,int len)
{
	int i,j;
	int temp;
	for(i=1; i<len; ++i)
	{
		temp = a[i];
		for( j=i-1; j>=0&&a[j]>temp;--j)
			a[j+1] =a[j];
		a[j+1] = temp;
	}
}

