/*************************************************************************
	> File Name: my_cat.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 11:17:47 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int index;
	char buf[1024] = "cat";
	for( index =1;index < argc;++index)
	{
		strcat(buf," ");
		strcat(buf,argv[index]);
	}
	system(buf);
	return 0;
}

