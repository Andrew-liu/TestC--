/*************************************************************************
	> File Name: server.c
	> Author: tanjx923
	> Mail:jas.firefly@hotmail.com 
	> Created Time: Tue 01 Jul 2014 02:12:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>
#include<fcntl.h>
#include<dirent.h>

void* send_message(void *arg);

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		perror("input error!\n");
		exit(-1);
	}
	int fd_server;
	char buf_pid[1024];
	fd_server=open(argv[1],O_RDONLY);
	fd_set read_set,read_set_back;//运用select对端口进行监听
	FD_ZERO(&read_set);
	FD_SET(fd_server,&read_set);
	struct timeval tm;
	//
	//******************************************************
	//
	while(1)
	{
		read_set_back=read_set;
		tm.tv_sec=0;
		tm.tv_usec=1000;
		select(1024,&read_set_back,NULL,NULL,&tm);
		//
		//************************************************
		//
		if(FD_ISSET(fd_server,&read_set_back))//若登录管子接收端有信息（这里由于登录管子只有一个，所以不用循环来顺序遍历）
		{
			memset(buf_pid,0,1024);
			if(read(fd_server,buf_pid,1024)==0)//若最后一个客户端把登录管子的写入端关了，则服务器的接收端的返回值为0
				continue;
			printf("%s is online\n",buf_pid);
			pthread_t stoc_tid;
			pthread_create(&stoc_tid,NULL,send_message,(void*)buf_pid);
		}
	}
}

void* send_message(void *arg)
{
	pthread_detach(pthread_self());
	char* buf_pid=(char*)arg;
	char buf[1024];
	char pipe_ctos[30]="";
	char pipe_stoc[30]="";
	int fd_read,fd_write;
	sprintf(pipe_ctos,"%s_ctos",buf_pid);
	sprintf(pipe_stoc,"%s_stoc",buf_pid);
	fd_read=open(pipe_ctos,O_RDONLY);
	printf("%d\n",fd_read);
	fd_write=open(pipe_stoc,O_WRONLY);
	printf("%d\n",fd_write);
	FILE *fp=fdopen(fd_write,"w");
	struct stat my_stat;
	DIR *pdir;
	struct dirent *pdirinfo;
	int fd;
	char buf_file[1024];
	while(memset(buf,0,1024),read(fd_read,buf,1024)>0)
	{
	//	printf("path:%s\n",buf);
		buf[strlen(buf)-1]='\0';
		if(strncmp(buf,"bye",3)==0)
		{
			fprintf(fp,"confirm");
			fflush(fp);
			break;
		}
		if(stat(buf,&my_stat)<0)
		{
			fprintf(fp,"The input path does not exist!\n");
			fflush(fp);
			continue;
		}
		if(S_ISDIR(my_stat.st_mode))
		{
			pdir=opendir(buf);
			while((pdirinfo=readdir(pdir))!=NULL)
			{
				fprintf(fp,"%s\n",pdirinfo->d_name);
				fflush(fp);
			}
		}
		else
		{
			fd=open(buf,O_RDONLY);
		//	printf("%d\n",fd);
			while(memset(buf_file,0,1024),read(fd,buf_file,1024)>0)
			{
				write(fd_write,buf_file,1024);
			}
			close(fd);
		}
	}
	printf("the %s is offline\n",buf_pid);
	sleep(1);
	close(fd_read);
	close(fd_write);
}