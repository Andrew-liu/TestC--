/*************************************************************************
	> File Name: test_p_exit.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 02:13:05 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
 * 1. atexit()程序退出时执行
 * 2._exit退出不刷新缓冲区
 * 3. exit退出刷新缓冲区
 * 4. ctrl+\
 *
 */
int main()
{
	if( fork() > 0)
	{
		sleep(5);
		int iret;
		wait(&iret);//传输函数
		printf("%x\n",iret);//包含两部分，1.程序退出码 2.退出信号
	}
	else
	{
		char buf[238];
		while( memset(buf,0,238),fgets(buf,238,stdin)!=NULL);
		exit(7);//0700 -> 0000 0111 0000 0000 

	}
}

