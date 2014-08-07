/*************************************************************************
	> File Name: del_mid_space.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 06 Jul 2014 04:12:56 PM HKT
 ************************************************************************/

#include "FTP.h"

void delete_mid_space(char *str)
{
	int i = -1;
	int j = 0;
	while( str[j] )
	{
		if( !isspace(str[j]) )
		{
			str[++i] = str[j];
		}else if( i != -1 && !isspace(str[i]) )
		{
			str[++i] = ' ';
		}
		++j;
	}
	for(; i>=0;--i)
	{
		if( !isspace(str[i]) )
			break;
	}
	str[++i] = '\0';
}

