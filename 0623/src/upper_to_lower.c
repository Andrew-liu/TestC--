/*************************************************************************
	> File Name: upper_to_lower.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 06:50:43 PM HKT
 ************************************************************************/

#include "txt.h"

void upper_to_lower(char *str)
{
	int i;
	for( i =0; i<strlen(str);++i)
	{
		if( isupper(str[i]) ) 
		{
			str[i] += 32;
		}
	}
}

