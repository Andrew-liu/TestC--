/*************************************************************************
	> File Name: strToint.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 05:41:55 AM PDT
 ************************************************************************/

#include "str.h"

int  strToint(char *str)
{
	int i;
	int n = 0;
	for(i=0;isspace(str[i]);++i)
		;//跳过开头空白符
	int sign = (str[i] == '-') ? -1:1;
	if( str[i]=='+' || str[i] == '-')
		i++;
//int count = 0;
	for( n ; isdigit(str[i]);++i)
	{
		n = n*10 +( str[i] - '0');
	}
	printf("%d \n",sign*n);
	return sign*n;
}
