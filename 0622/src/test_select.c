/*************************************************************************
	> File Name: test_select.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 22 Jun 2014 10:19:14 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>

#define filename1 "./a.txt"
#define filename2 "./dir.c"
int main()
{
	char buf[10] = {0};
	int fd1 = open(filename1,O_RDWR);
	int fd2 = open(filename2,O_RDWR);
	int fd3 = open(filename1,O_RDWR);
	int fd4 = open(filename2,O_RDWR);
	if( -1 == fd1 || -1 == fd2 || -1 == fd3 || -1 == fd4 )
	{
		perror("open faied\n");
		exit(-1);
	}
	fd_set fdrd,fdwr;//绑定读写集合
	FD_ZERO(&fdrd);
	FD_ZERO(&fdwr);
	FD_SET(fd1,&fdrd);//与读绑定
	FD_SET(fd2,&fdrd);
	FD_SET(fd3,&fdwr);
	FD_SET(fd4,&fdwr);
	int max1 = fd1>fd2?fd1:fd2;
	int max2 = fd3>fd4?fd3:fd4;
	int max  = max1>max2?max1:max2;
	struct timeval tv;
	tv.tv_sec = 2;//用于记录时间，表示过这些时间不响应就退出
	tv.tv_usec = 0;
	while(1)
	{
		if( select(max+1,&fdrd,&fdwr,NULL,&tv) == -1)
		{
			perror("select error\n");
			break;
		}
		if(FD_ISSET(fd1,&fdrd))
		{
			read(fd1,buf,sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if(FD_ISSET(fd2,&fdrd))
		{
			read(fd2,buf,sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if(FD_ISSET(fd3,&fdwr))
		{
			write(fd3,buf,sizeof(buf));
			sleep(2);
		}
		if(FD_ISSET(fd4,&fdwr))
		{
			write(fd4,buf,sizeof(buf));
			sleep(2);
		}
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
	}
}

