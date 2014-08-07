/*************************************************************************
	> File Name: client.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 01 Jul 2014 06:42:02 PM HKT
 ************************************************************************/
/*
 * 客户端功能：
 * 1.向服务器发送文件路径或者目录路径
 * 2.接受服务器传回的数据
 * 3.将数据输出成文件或输出到屏幕
 *
 *
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define SIZE 1024
#define FIFO_SERVER "./server.fifo"
int main(int argc,char *argv[])
{
	char path[1024];
	char re_fifo_name[128];
	char receive[SIZE];
	if( argc != 2 )
	{
		perror("error\n");
		exit(-1);
	}
	int fd_server = open(FIFO_SERVER,O_WRONLY);
	printf("OK\n");
	if( -1 == fd_server )
	{
		perror("open error\n");
		exit(-1);
	}
	sprintf(path,"%d %s",getpid(),argv[1]);
	puts(path);
	FILE *fp_server = fdopen(fd_server,"w");
	fprintf(fp_server,"%s",path);
	fflush(fp_server);

	sprintf(re_fifo_name,"%d_receive.fifo",getpid());
	mkfifo(re_fifo_name,0666);

	int fd_receive = open(re_fifo_name,O_RDONLY);
	if( -1 == fd_receive )
	{
		perror("open re_fifo error\n");
		exit(-1);
	}
	FILE *fp_receive = fdopen(fd_receive,"r");
//receive from server
	while( memset(receive,0,SIZE),fread(receive,1,SIZE,fp_receive) >0 )
	{
		char newname[128] = "";
		memset(newname,0,128);
		strcpy(newname,argv[1]);
		strcat(newname,".bak");
		FILE *fp_write = fopen(newname,"wb");
		if( NULL == fp_write )
		{
			perror("write error\n");
			exit(-1);
		}
		fwrite(receive,1,SIZE,fp_write);
	}
	fclose(fp_server);
	fclose(fp_receive);
	fclose(fp_receive);
	close(fd_server);
	close(fd_receive);
	unlink(re_fifo_name);
	return 0;
}

