/*************************************************************************
	> File Name: myclient.c
	> Author: andrew_liu
	> Mail:1095511864@qq.com 
	> Created Time: Fri 27 Jun 2014 04:42:58 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
void handler(int num)
{
	wait(NULL);
	exit(-1);
}
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Not Input PipeName!\n");
		exit(-1);
	}
	int fd_sever;//服务器管道标识符
	int fd_read,fd_write;//读写管道标识符
	char buf[1024];
	char fifo_write[128]="";
	char fifo_read[128]="";
	int pid;
	fd_sever=open(argv[1],O_WRONLY);//向服务器管道写入信息
	sprintf(fifo_read,"%d_read.fifo",getpid());
	sprintf(fifo_write,"%d_write.fifo",getpid());
	mkfifo(fifo_read,0666);
	mkfifo(fifo_write,0666);
	FILE *fp=fdopen(fd_sever,"w");
	if(fp==NULL)
	{
		perror("sever link failed!\n");
		exit(-1);
	}
	fprintf(fp,"%d",getpid());//提示服务器上线，并通过进程号告诉服务器自己的读写管道
	fflush(fp);
	fd_read=open(fifo_read,O_RDONLY);
	fd_write=open(fifo_write,O_WRONLY);//文件
	printf("%d begin talk!",getpid());
	if((pid=fork())>0)//父进程负责写
	{
		close(fd_read);
		signal(17,handler);
		//格式化输入
		FILE *fdw=fdopen(fd_write,"w");
		if(fdw==NULL)
		{
			printf("the fd_write is failed\n");
			exit(-1);
		}
		while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
		{
			fprintf(fdw,"from %d :%s",getpid(),buf);
			fflush(fdw);
		}
		fprintf(fdw,"%s","bye");
		fflush(fdw);
		printf("kill child!\n");
		close(fd_write);
		kill(pid,9);
		unlink(fifo_read);
		unlink(fifo_write);
		while(1);
	}
	else
	{
		close(fd_write);
		while(memset(buf,0,1024),read(fd_read,buf,1024)>0)
		{
			fflush(stdout);
			write(1,buf,strlen(buf));
			fflush(stdout);
		}
		close(fd_read);
	}
	return 0;
}

