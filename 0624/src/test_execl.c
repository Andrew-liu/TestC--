/*************************************************************************
	> File Name: test_execl.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 02:26:50 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int index;
	char *buf[10];
	printf("execl begin\n");
//	char *buf[]= {"./hello","hello","world",NULL};
	for( index = 0;index < argc;++index)
	{
		buf[index] = argv[index];
	}
	buf[index] = NULL;
//	execl("./hello","./hello","hello","world",NULL);//1.调用的程序全路径， 2.调用程序的名字和参数
//	execl("/bin/ls","ls","-l",NULL);
	execvp(buf[1],buf);
	printf("end\n");
	return 0;
}

