/*************************************************************************
	> File Name: test_select.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 24 Jun 2014 04:31:13 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define filename1 "./a.txt"
#define filename2 "./b.txt"
//1.初始化集合，并将要监听的描述符放到集合中去
//2.设置监听间隔时间
//3.开始监听（select扫描集合，只需扫描到最大描述符)
//4.判断哪个文件活动了，并做相应的处理
int main()
{
	char buf[1024];
	int fd1 = open(filename1,O_RDONLY);
	int fd2 = open(filename2,O_RDONLY);
	if( -1==fd1 || -1==fd2)
	{
		perror("open error\n");
		exit(-1);
	}
	fd_set my_read,my_ready;
	FD_ZERO(&my_read);
	FD_SET(fd1,&my_read);
	FD_SET(fd2,&my_read);
	int max_fd = fd1>fd2?fd1:fd2;
	struct timeval t;
//	t.tv_sec = 4;
//	t.tv_usec = 0;
	while(1)
	{
		t.tv_sec = 4;
		t.tv_usec = 0;
		my_ready = my_read;
		int ired = select(max_fd+1,&my_ready,NULL,NULL,&t);
		printf("monitor has read %d\n",ired);
		if(FD_ISSET(0,&my_read))
		{
			memset(buf,0,sizeof(buf));
			read(0,buf,sizeof(buf));
			printf("keyboard: %s\n",buf);
		}
		if(FD_ISSET(fd1,&my_ready))
		{
			memset(buf,0,sizeof(buf));
			read(fd1,buf,sizeof(buf));
			printf("a.txt: %s\n",buf);
		}
		if( FD_ISSET(fd2,&my_ready))
		{
			memset(buf,0,sizeof(buf));
			read(fd2,buf,sizeof(buf));
			printf("b.txt: %s\n",buf);
		}

	}
	close(fd1);
	close(fd2);
	return 0;
}

