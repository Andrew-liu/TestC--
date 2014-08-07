/*************************************************************************
	> File Name: lule.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 11:49:53 AM HKT
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char const *argv[])
{
	char buf[100]="./lule";
	int count  =atoi(argv[1])+1;
	char s_count[10];
	sprintf(s_count," %d",count);
	strcat(buf,s_count);
	printf("%s\n",buf);
	system(buf);
	return 0;
}
