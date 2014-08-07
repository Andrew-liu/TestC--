/*************************************************************************
	> File Name: test_fork.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 24 Jun 2014 10:44:24 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
/*
 * fork 创建子进程
 */
int main()
{
	printf("The progress pid is %d\n",getpid());
	pid_t pn = fork();
	if(pn == -1)
	{
		printf("create fail\n");
	}
	else if( pn != 0)
	{
		printf("The father pid is %d\n",getpid());
		pid_t pn2 = fork();
		if(pn2 == -1)
		{
			printf("create bro fail\n");
		}
		else if( pn2 != 0 )
		{
			printf("The bro pid is %d\n",pn2);
		}
		else
		{
			printf("create bro success,pid is %d father is %d\n",getpid(),getppid());
		}

	//	printf("kid p success, pid id %d ppid is %d\n",getpid(),getppid());
		printf("father return , kid pid is %d\n",pn);
	}
	else
	{
		printf("kid p success, pid id %d ppid is %d\n",getpid(),getppid());
	//	printf("father return , kid pid is %d\n",pn);
	}
	return 0;

}

