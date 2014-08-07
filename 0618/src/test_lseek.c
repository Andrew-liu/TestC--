/*************************************************************************
	> File Name: test_lseek.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 08:12:04 AM PDT
 ************************************************************************/
//off_t lseek(int fd,off_t offset,int whence)
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define filename "./aaa.txt"
int main()
{
	int fo = open(filename,O_WRONLY);
	lseek(fo,1024,SEEK_SET);
	write(fo,"a",1);
	close(fo);
	return 0;

}

