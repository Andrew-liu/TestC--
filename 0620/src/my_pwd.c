/*************************************************************************
	> File Name: my_pwd.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:18:22 PM PDT
 ************************************************************************/

#include <unistd.h>

int main(int argc,char * argv[])
{
	printf("current dir is %s",getcwd(NULL,0));
}

