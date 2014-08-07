/*************************************************************************
	> File Name: client.c
	> Author: tanjx923
	> Mail:jas.firefly@hotmail.com 
	> Created Time: Tue 01 Jul 2014 02:12:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>
#include<fcntl.h>

void* send_path(void *arg);
void* rec_message(void *arg);

pthread_cond_t pipe_open;
pthread_mutex_t pipe_mutex;

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		perror("input error!\n");
		exit(-1);
	}
	pthread_cond_init(&pipe_open,NULL);
	pthread_mutex_init(&pipe_mutex,NULL);
	char pipe_ctos[50]="";
	sprintf(pipe_ctos,"%u_ctos",getpid());
	mkfifo(pipe_ctos,0666);
	char pipe_stoc[50]="";
	sprintf(pipe_stoc,"%u_stoc",getpid());
	mkfifo(pipe_stoc,0666);
	int fd_server;
	fd_server=open(argv[1],O_WRONLY);
	FILE *fp_server=fdopen(fd_server,"w");
	fprintf(fp_server,"%d",getpid());
	fflush(fp_server);
	//
	//**********************************
	//
	pthread_t ctos_tid,stoc_tid;
	pthread_create(&ctos_tid,NULL,send_path,(void*)pipe_ctos);
	pthread_create(&stoc_tid,NULL,rec_message,(void*)pipe_stoc);
	pthread_join(ctos_tid,NULL);
	pthread_join(stoc_tid,NULL);
	close(fd_server);
	pthread_cond_destroy(&pipe_open);
	pthread_mutex_destroy(&pipe_mutex);
	return 0;
}

void* send_path(void *arg)
{
	char *pipe_ctos=(char*)arg;
	int fdw_ctos;
	fdw_ctos=open(pipe_ctos,O_WRONLY);
	printf("%d\n",fdw_ctos);
	FILE *fp_ctos=fdopen(fdw_ctos,"w");

	pthread_cond_signal(&pipe_open);

	char buf[1024];
	while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
	{
		fprintf(fp_ctos,"%s",buf+4);
	//	printf("path:%s\n",buf+4);
		fflush(fp_ctos);
	}
	fprintf(fp_ctos,"bye");
	fflush(fp_ctos);
	sleep(1);
	close(fdw_ctos);
	unlink(pipe_ctos);
}

void* rec_message(void *arg)
{
	char *pipe_stoc=(char*)arg;
	int fdr_stoc;

	pthread_mutex_lock(&pipe_mutex);
	pthread_cond_wait(&pipe_open,&pipe_mutex);

	fdr_stoc=open(pipe_stoc,O_RDONLY);
	printf("%d\n",fdr_stoc);
	char buf[1024];
	while(memset(buf,0,1024),read(fdr_stoc,buf,1024)>0)
	{
		if(strncmp(buf,"confirm",7)==0)
			break;
		write(1,buf,strlen(buf));
	}
	close(fdr_stoc);
	unlink(pipe_stoc);
}