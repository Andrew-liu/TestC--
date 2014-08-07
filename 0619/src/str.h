/*************************************************************************
	> File Name: str.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 05:42:09 AM PDT
 ************************************************************************/
#ifndef _str
#define _str
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int  strToint(char *str);
void intTostr(int n,char *str);
void str_reserve(char *str);
void floatTostr(float n,char *str);
#endif
