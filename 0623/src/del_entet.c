/*************************************************************************
	> File Name: del_entet.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 08:40:20 PM HKT
 ************************************************************************/

#include "txt.h"

void del_enter(char *str)
{
	int end;
	for( end = strlen(str)-1;str[end]=='\n';--end)
		;
	str[end+1]='\0';
}
