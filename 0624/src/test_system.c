/*************************************************************************
	> File Name: test_system.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 10:56:44 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char buf[256]="";
	int index;
	sprintf(buf,"./hello");
	for( index = 1;index< argc;++index)
	{
		strcat(buf," ");
		strcat(buf,argv[index]);
	}
	system(buf);

}

