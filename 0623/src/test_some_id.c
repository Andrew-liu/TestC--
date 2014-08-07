/*************************************************************************
	> File Name: test_some_id.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 09:04:53 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("uid:%d gid:%d euid:%d egid %d\n",getuid(),getgid(),geteuid(),getegid());//用户ID,组ID,有效用户ID,有效组ID
	return 0;
}


