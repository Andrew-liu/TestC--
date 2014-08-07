/*************************************************************************
	> File Name: test_everysat.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 08:50:05 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#define filename "./The_Holy_Bible.txt"
int main()
{
	int fd = open(filename,O_RDONLY);
	struct stat buf;
	if(-1 == fd)
	{
		perror("open fail\n");
		exit(-1);
	}
	int iret = fstat(fd,&buf);
	if(S_ISREG(buf.st_mode))
	{
		printf("It's regular file\n");
	}
	if(S_ISDIR(buf.st_mode))
	{
		printf("it's dir\n'");
	}
	if(S_ISLNK(buf.st_mode))
	{
		printf("it's link\n'");
	}
	printf("The size is %d\n",buf.st_size);
//struct tm可以通过其获得日期和时间
//表示时间的类型一般用time_t
//gmitime将日历时间转化为世界标准时间
	struct tm *p;
	time_t t = buf.st_atime;
	p = gmtime(&t);
	printf("%4d-%02d-%02d	%02d:%02d:%02d\n",(1990+p->tm_year),(1+p->tm_mon),(p->tm_mday),(8+p->tm_hour),p->tm_min,p->tm_sec);
	close(fd);
	return 0;
}

