/*************************************************************************
	> File Name: client.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 27 Jun 2014 02:53:48 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
/*
 * 1.用命令行参数传“上线管道”名,告诉服务器上线
 * 2.利用唯一的pid动态创建读写管道，用作向服务器发送数据
 * 3.通过“上线管道”将客户端进程id传给服务器，以让服务器得到读写管道
 * 4.打开读写管道，创建父子进程，进行读写操作
 * 5.发送结束，跟服务器说bye,杀死孩子，关闭钢管
 *
 */
void my_hand(int num)

{
	printf("caole\n");
	wait(NULL);
	exit(1);
}
int main(int argc,char *argv[])
{
	pid_t pid;
	int fd_read_fifo,fd_write_fifo;
	char buf[1024];
	char fifo_read_name[128]  = "";
	char fifo_write_name[128] = "";
	if( argc != 2 )
	{
		perror("error\n");
		exit(-1);
	}
	puts(argv[1]);
	int fd_login_wr = open(argv[1],O_WRONLY);
	printf("open\n");
	if( -1 == fd_login_wr )
	{
		perror("open error\n");
		exit(-1);
	}
	FILE *fp_login_wr = fdopen(fd_login_wr,"w");
	if( fp_login_wr == NULL)
	{
		perror("111error\n");
	}
	sprintf(fifo_read_name,"%d_receive.fifo",getpid());
	mkfifo(fifo_read_name,0666);
	sprintf(fifo_write_name,"%d_send.fifo",getpid());
	mkfifo(fifo_write_name,0666);
	fprintf(fp_login_wr,"%d",getpid());
	fflush(fp_login_wr);
	 fd_read_fifo  = open(fifo_read_name,O_RDONLY);
	 fd_write_fifo = open(fifo_write_name,O_WRONLY);
	printf("id %d on\n",getpid());
	if( (pid = fork()) > 0)//send
	{
		close(fd_read_fifo);
		signal(17,my_hand);
		FILE *fp_write = fdopen(fd_write_fifo,"w");
		while ( memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL )
		{
			fprintf(fp_write,"from %d: %s",getpid(),buf);
			fflush(fp_write);
		}
		fprintf(fp_write,"%s","bye");
		printf("mabi\n");
		fflush(fp_write);
		close(fd_write_fifo);
		kill(pid,9);
	//	close(fd_write_fifo);
		unlink(fifo_write_name);
		unlink(fifo_read_name);
		while(1);
	}
	else
	{
		close(fd_write_fifo);
		while(memset(buf,0,1024),read(fd_read_fifo,buf,1024)>0)
		{
			write(1,buf,strlen(buf));
		}
		close(fd_read_fifo);
	}





/*	if( argc != 2 )
	{

	}
	int fd_server = open(argv[0],O_WRONLY);
	if( -1 == fd_server )
	{

	}
	FILE *fp = fdopen(fd_server,"w");
	char fifo_read_name[32] = "";
	char fifo_write_name[32] = "";
	sprintf(fifo_read_name,"%d_read.fifo",getpid());
	mkfifo(fifo_read_name,0666);*/





}

