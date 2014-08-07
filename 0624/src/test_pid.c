/*************************************************************************
	> File Name: test_pid.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 24 Jun 2014 10:09:39 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * 1.进程号(pid)     : getpid() 获取
 * 2.父进程号(ppid)  : getppid()获取
 * 3.真实用户id(uid) : getuid() 获取
 * 4.真实组id(gid)   : getgid() 获取
 * 5.有效用户id(euid): geteuid()获取
 * 6.有效组id(egid)  : getegid()获取
 *返回值为无符号数
 * */
int main()
{
	printf("The progress pid  is %u\nThe progress ppid is %u\nThe progress uid  is %u\nThe progress gid  is %u\nThe progress euid is %u\nThe progress egid is %u\n",getpid(),getppid(),getuid(),getgid(),geteuid(),getegid());
	return 0;
}
