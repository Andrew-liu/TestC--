/*************************************************************************
	> File Name: mysever.c
	> Author: andrew_liu
	> Mail:1095511864@qq.com 
	> Created Time: Fri 27 Jun 2014 05:13:12 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
typedef struct tag //结构体用于记录用于读写管道的标识符
{
	int s_read;
	int s_write;
}CLIENT_NODE;
#define NUM 500  //每个客户端需要两根管道，一共可以容纳1024个文件描述符，允许500+个客户端在线
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Not Input PipeName!\n");
		exit(-1);
	}
	int fd_sever;
	int client_pid;
	char buf[1024];
	char newbuf[1024];
	char fifo_read[128]="";
	char fifo_write[128]="";
	int fd_read,fd_write;
	struct timeval tm;
	int index,sendindex;
	CLIENT_NODE infor[NUM];
	memset(infor,-1,NUM*sizeof(CLIENT_NODE));
	fd_sever=open(argv[1],O_RDONLY);
	fd_set set_read,set_ready;
	FD_ZERO(&set_read);
	FD_SET(fd_sever,&set_read);
	while(1)
	{
		tm.tv_sec=0;
		tm.tv_usec=1000;//1毫秒
		set_ready=set_read;
		select(1024,&set_ready,NULL,NULL,&tm);
		if(FD_ISSET(fd_sever,&set_ready))
		{
			memset(buf,0,1024);
			if(read(fd_sever,buf,1024)==0)
			{
				continue;
			}
			client_pid=atoi(buf);//获取客户端进程号
			printf("pif:%d up\n",client_pid);
			sprintf(fifo_read,"%d_write.fifo",client_pid);
	//		printf("OK1\n");
			sprintf(fifo_write,"%d_read.fifo",client_pid);
	//		printf("ok2\n");
			fd_write=open(fifo_write,O_WRONLY);
	//		printf("ok3\n");
			fd_read=open(fifo_read,O_RDONLY);
	//		printf("ok4\n");
			for(index=0;index<NUM;index++)
			{
				printf("%d ",index);
				if(infor[index].s_read==-1)//是否有空闲列表
				{
					break;
				}
			}
			if(index<NUM)
			{
			//	printf("ok set\n");
				infor[index].s_read=fd_read;
				infor[index].s_write=fd_write;
			//	printf("set over\n");
			}
			else
			{
				printf("sever kill\n");
				kill(client_pid,0);
				close(fd_read);
				close(fd_write);
				unlink(fifo_read);
				unlink(fifo_write);
			}
			FD_SET(fd_read,&set_read);	//放入监听集合
		
		}
			for(index=0;index<NUM;index++)
			{
		//		printf("new%d ",index);
				if(FD_ISSET(infor[index].s_read,&set_ready))
				{
					printf("read%d ",index);
					memset(newbuf,0,1024);
					read(infor[index].s_read,newbuf,1024);
					if(strncmp(newbuf,"bye",3)==0)  //下线
					{
						printf("a client out!\n");
						close(infor[index].s_read);
						close(infor[index].s_write);
						FD_CLR(infor[index].s_read,&set_read);
						memset(infor+index,-1,sizeof(CLIENT_NODE));
					}
					else
					{
						for(sendindex=0;sendindex<NUM;sendindex++)
						{
							if(infor[sendindex].s_write!=-1)
							{
								write(infor[sendindex].s_write,newbuf,strlen(newbuf));
							}
						}
						
					}
				}
			}
	}
	return 0;
}

