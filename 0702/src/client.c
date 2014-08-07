/*************************************************************************
	> File Name: client.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 10:39:05 AM HKT
 ************************************************************************/

#include "tcp_socket.h"

int main(int argc,char *argv[])
{
	MSG msg,recv_msg;
	int total = 0;
	int fd_client = tcp_connect(argv[1],atoi(argv[2]));

	memset(&msg,0,sizeof(msg));
	char aa[100] = "REAL Sq";
	strcpy(msg.s_buf,argv[3]);
	msg.s_len = strlen(msg.s_buf);
	send(fd_client,&msg,msg.s_len+MSG_LEN,0);

	char new_filename[128]="";
	strcpy(new_filename,msg.s_buf);
	strcat(new_filename,".bak");
	int fd_write = open(new_filename,O_WRONLY|O_CREAT,0666);
	while(1)
	{
		memset(&recv_msg,0,sizeof(recv_msg));
		recv(fd_client,&recv_msg,MSG_LEN,0);
		total += recv_msg.s_len;
			printf("downloading...:%.2lfkb\n",(double)total/1024);	
		if(recv_msg.s_len > 0 )
		{
			recv(fd_client,&recv_msg.s_buf,recv_msg.s_len,0);
			write(fd_write,recv_msg.s_buf,recv_msg.s_len);
		}
		else
		{
			break;
		}
	}
	close(fd_client);
	close(fd_write);
}
