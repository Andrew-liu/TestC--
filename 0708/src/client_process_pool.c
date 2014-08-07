/*************************************************************************
	> File Name: client_process_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 08 Jul 2014 04:46:48 PM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int main(int argc,char *argv[])
{
	char recv_buf[1024];
	char send_buf[1024];
	int len;
	if( 3 != argc )
		ERR_EXIT("argc error");
	int fd_client = tcp_connect(argv[1],atoi(argv[2]));
	while( bzero(send_buf,1024),fgets(send_buf,1024,stdin)!=NULL )
	{
		len = strlen(send_buf);
		send_buf[len-1] = '\0';
		send(fd_client,&len,sizeof(int),0);
		send(fd_client,send_buf,len,0);
		//recv
		bzero(recv_buf,1024);
		recv(fd_client,&len,sizeof(int),0);
		recv(fd_client,recv_buf,len,0);
		printf("From Server:%s\n",recv_buf);
	}
	len = 0;
	send(fd_client,&len,sizeof(int),0);
}
