/*************************************************************************
	> File Name: selcet_sort.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 12:06:46 AM PDT
 ************************************************************************/

#include "func.h"

void select_sort(int *a,int len)
{
	int i,j;
	int min;
	int temp;
	for( i=0;i<len;++i)
	{
		min = i;
		for( j=i+1;j<len;++j)
		{
			if(a[j] <= a[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min]=temp;
		}
	}

}

