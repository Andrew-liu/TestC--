/*************************************************************************
	> File Name: test_##.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 11:08:10 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define _SOCKADDR_COMMON(a) a##byebye

int main()
{
	char word[] = "boom";
	printf("%s\n",_SOCKADDR_COMMON(word));
	return 0;
}

