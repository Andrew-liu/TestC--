/*************************************************************************
	> File Name: quick_sort.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 12:23:08 AM PDT
 ************************************************************************/

#include "func.h"

int partion(int *a,int len)
{
	int low = 0;
	int high = len-1;
	int key = a[0];
	int temp;
	while( low < high)
	{
		while(low<high && a[high]>=key)
			--high;
		if(low<high)
		{
			temp = a[low];
			a[low]=a[high];
			a[high]=temp;
		}
		while(low<high && a[low]<key)
			++low;
		if(low<high)
		{
			temp = a[low];
			a[low] =a[high];
			a[high]=temp;
		}

	}
	return low;

}
void quick_sort(int *a,int len)
{
	int mid;
	if(len<5)
		insert_sort(a,len);
	else
	{
		mid = partion(a,len);
		quick_sort(a,mid);
		quick_sort(&a[mid+1],len-mid-1);
	}
}
