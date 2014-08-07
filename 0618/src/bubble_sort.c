/*************************************************************************
	> File Name: bubble_sort.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 12:44:07 AM PDT
 ************************************************************************/

#include "func.h"
void bubble_sort(int *a,int len)
{
	int i,j;
	int temp;
	for(i=0;i<len;++i)
	{
		for(j=0;j<len-i-1;++j)
		{
			if(a[j]>=a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

