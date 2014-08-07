/*************************************************************************
	> File Name: client_select.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 28 Jun 2014 08:46:48 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string.h>
/*typedef struct tag
{
	int fd_re;
	int fd_wr;
}*/


int main(int argc,char *argv[])
{
	char receive_name_fifo[128] = "";
	char send_name_fifo[128] = "";
	char buf[1024];
	int    fd_receive,fd_send,fd_login;
	fd_set read_set,ready_set;
	struct timeval t;
	if( argc != 2 )
	{
		perror("error\n");
		exit(-1);
	}
	fd_login = open ( argv[1],O_WRONLY);
	sprintf(receive_name_fifo,"%d_receive.fifo",getpid());
	mkfifo(receive_name_fifo,0666);
	sprintf(send_name_fifo,"%d_send.fifo",getpid());
	mkfifo(send_name_fifo,0666);
	printf("OK\n");

	FILE *fp_login = fdopen(fd_login,"w");
	fprintf(fp_login,"%d",getpid());
	fflush(fp_login);
		
	fd_receive = open(receive_name_fifo,O_RDONLY);
	fd_send    = open(send_name_fifo,O_WRONLY);
	FILE *fp_wr = fdopen(fd_send,"w");
	printf("success log on\n");
	
	FD_ZERO(&read_set);
	FD_SET(fd_receive,&read_set);
	FD_SET(0,&read_set);

	while(1)
	{
	//	t.tv_sec  = 0;
	//	t.tv_usec = 1000;
		ready_set = read_set;
		if( -1 == select(fd_receive+1,&ready_set,NULL,NULL,NULL) )
		{
			perror("select error\n");
			exit(-1);
		}
		if( FD_ISSET(fd_receive,&ready_set) )
		{
			printf("OK3\n");
			memset(buf,0,1024);
			if( read(fd_receive,buf,1024) == -1 )
				break;
			write(1,buf,strlen(buf));
		}
		if( FD_ISSET(0,&ready_set) )
		{
			printf("OK4\n");
			memset(buf,0,1024);
			if( fgets(buf,1024,stdin) == NULL )
				break;
			if ( buf[0] = '\n' )
				continue;
			fprintf(fp_wr,"from %d: %s",getpid(),buf);
			fflush(fp_wr);
		}
	}
	fclose(fp_wr);
	close(fd_receive);
	unlink(receive_name_fifo);
	unlink(send_name_fifo);
	return 0;
}

