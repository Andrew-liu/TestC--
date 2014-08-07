/*************************************************************************
	> File Name: file_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 11:45:07 PM PDT
 ************************************************************************/

#include "file.h"

int main(int argc,char *argv[])
{
	if (argc < 2)
	{
		scan_dir("./");
	}
	else
	scan_dir(argv[1]);
	return 0;
}
