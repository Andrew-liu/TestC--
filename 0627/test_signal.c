/*************************************************************************
	> File Name: test_signal.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 27 Jun 2014 09:36:14 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void my_handler(int num)
{
	printf("num = %d\n",num);
}
int main()
{
	while(1)
	{
		signal(2,my_handler);
		printf("hello\n");
		sleep(2);
	}
	return 0;
}
