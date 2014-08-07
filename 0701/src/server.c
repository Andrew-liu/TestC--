/*************************************************************************
	> File Name: server.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 01 Jul 2014 07:14:14 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <fcntl.h>
#define FIFO_SERVER "./server.fifo"
#define SIZE 1024


void get_path(char *str);
void get_pid(char *str);
int is_dir(char *str );//0 is dir other is not

void *copy_file(void *arg)
{
	pthread_detach( pthread_self() );
	char *path = (char *)malloc(128);
	char *pid  = (char *)malloc(128);
	strcpy(path,(char *)arg);
	puts(path);
	strcpy(pid,(char *)arg);
	puts(pid);
	char send_fifo_name[128];
	char buf[SIZE];
	get_path(path);
	printf("path = %s\n",path);
	get_pid(pid);
	printf("pid = %s\n",pid);
	sprintf(send_fifo_name,"%d_receive.fifo",atoi(pid));
	int fd_wr = open(send_fifo_name,O_WRONLY);
	if( -1 == fd_wr )
	{
		perror("write error\n");
		exit(-1);
	}
	FILE *fp_wr = fdopen(fd_wr,"w");


	FILE *fp_rd = fopen(path,"r");
	if( NULL == fp_rd )
	{
		perror("open error\n");
		exit(-1);
	}

	while( memset(buf,0,1024),fread(buf,1,SIZE,fp_rd) >0 )
	{
		fwrite(buf,1,SIZE,fp_wr);
	}
	fclose(fp_rd);
	fclose(fp_wr);
	close(fd_wr);
}




int main(int argc,char *argv[] )
{

	char re_path[128];
	int fd_server = open(FIFO_SERVER,O_RDONLY);
	printf("OK\n");
	if( -1 == fd_server )
	{
		perror("open error\n");
		exit(-1);
	}
//	memset(re_path,0,128);
	//receive from client
	while(memset(re_path,0,128),read(fd_server,re_path,1024)>0)
	{
	//	fprintf(stdout,"from client:%d,want read %s\n",re_path);
		char *p = (char *)malloc(128);
		strcpy(p,re_path);
		puts(re_path);
		puts(p);
		if( 0 == is_dir(re_path) )//copy dir
		{
			printf("This is dir\n");

		}
		else//copy file
		{
			printf("OK1\n");
			pthread_t tid;
			pthread_create(&tid,NULL,copy_file,(void*)p);

		}

	}

}

void get_path(char *str)
{
	char buf[32];
	int pos = 0;
	memset(buf,0,32);
	while(sscanf(str+pos,"%s",buf) == 1 )
	{
		pos = pos + strlen(buf)+1;
	}
	strcpy(str,buf);
}
void get_pid(char *str)
{
	char buf[32] = "";
	sscanf(str,"%s",buf);
	strcpy(str,buf);
}
int is_dir(char *str )//0 is dir other is not
{
	get_path(str);
	char path[128];
	getcwd(path,128);
	int n = chdir(str);
	chdir(path);
	return n;
	
}
