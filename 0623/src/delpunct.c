/*************************************************************************
	> File Name: delpunct.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 06:54:01 PM HKT
 ************************************************************************/

#include "txt.h"
void del_punct(char *str)
{
	int i;
	for( i =0;i<strlen(str);++i)
	{
		if( ispunct(str[i]) )
		{
			str[i] = ' ';
		}
	}
}

