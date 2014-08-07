/*************************************************************************
	> File Name: floatTostr.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:17:57 AM PDT
 ************************************************************************/

#include "str.h"
void floatTostr(float n,char *str)
{
	int sign = n;
	int i=0;
	if(n<0)
		n=-n;
	int a =(int)n;//保存小数点之前
	printf("a=%lf\n",n);
	float b = n-a;
	printf("b=%lf\n",b);
	do
	{
		b *=10;//2.8//8.0
		printf("c=%lf\n",b);
		str[i++] =(int)b+'0';
		b =(b-(int)b);//0.8
		printf("d=%lf\n",b);
	}while( b!=0.0000);
	str[i++] = '.';
	do
	{
		str[i++] = a%10 +'0'; 
		printf("%c ",str[i]);
	}while((a/=10)>0);
	if( sign < 0)
		str[i] = '-';
	str[++i] = '\0';
	str_reserve(str);
}
