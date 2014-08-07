/*************************************************************************
	> File Name: reserveStr.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:10:30 AM PDT
 ************************************************************************/

#include "str.h"

void str_reserve(char *str)
{
	int begin = 0;
	int end = strlen(str)-1;
	char temp;
	do
	{
		temp = str[end];
		str[end--] = str[begin];
		str[begin++] = temp;
	}while(begin<end);

}

