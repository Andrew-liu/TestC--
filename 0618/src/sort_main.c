/*************************************************************************
	> File Name: sort_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 17 Jun 2014 11:28:01 PM PDT
 ************************************************************************/

#include "func.h"
int main()
{
	int a[LEN];
	int i;
/*	getarray(a,LEN);*/
	for(i=0;i<LEN;++i)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,LEN);
	print(a,LEN);
	insert_sort(a,LEN);
	print(a,LEN);
	select_sort(a,LEN);
	print(a,LEN);
	quick_sort(a,LEN);
	print(a,LEN);
	return 0;
}










