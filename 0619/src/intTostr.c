/*************************************************************************
	> File Name: intTostr.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:04:57 AM PDT
 ************************************************************************/

#include "str.h"
void intTostr(int n,char *str)
{
	int i=0;
	int sign =n;
	if( n < 0)
		n = -n;
	do
	{
		str[i++] = n%10 + '0';
	}while( (n/=10)>0);
	if( sign <0)
		str[i] = '-';
	str[++i] = '\0';
	str_reserve(str);
}

