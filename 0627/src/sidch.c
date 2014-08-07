/*************************************************************************
	> File Name: sidch.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 27 Jun 2014 10:06:33 AM HKT
 ************************************************************************/
/*
 *sigpipe
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void my_handler(int num)
{
	printf("sign num is %d\n",num);
}
int main()
{
	if( fork()>0 )
	{
		signal(17,my_handler);
	}
	else
	{
		sleep(2);
		exit(0);
	}
}
