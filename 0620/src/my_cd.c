/*************************************************************************
	> File Name: my_cd.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 06:25:19 PM PDT
 ************************************************************************/

#include <unistd.h>
#include <errono.h>
#include <stdio.h>
#include <stdlib.h>
#define maindir "~"
int main(int argc,char *argv[])
{
	int rc;
	if(argc < 2)
	{
		rc = chdir(maindir);
	}
	else
	{
		rc = chdir(argv[1]);
	}
	if( rc = !=0)
	{
		perror("change fail\n");
		exit(-1);
	}
	return 0;
}


