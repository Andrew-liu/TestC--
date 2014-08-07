/*************************************************************************
	> File Name: str_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 05:49:30 AM PDT
 ************************************************************************/

#include "str.h"
int main()
{
	char str[1024] = "-1234";
	char str1[1024];
	int n1 = -1234;
	float f1 = -1234.56;
	floatTostr(f1,str1);
//	int n =  strToint(str);
//	printf("strToint is %d\n",n);
//	intTostr(n1,str1);
	puts(str1);
}

