/*************************************************************************
	> File Name: my_fork.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 04:58:31 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	printf("begin\n");
	printf("father pid is %d\n",getpid());
	pid_t p = fork();
	if( p == 0)
	{
		printf("son: id %d\n",getpid());
		sleep(10);
		exit(10);
	}
	else
	{
		printf("father: myson_id %d\n",p);
		pid_t w = wait(NULL);
		printf("byebye son\n");
		exit(10);
	}
}

