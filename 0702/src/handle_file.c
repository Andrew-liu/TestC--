/*************************************************************************
	> File Name: handle_file.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 03:54:35 PM HKT
 ************************************************************************/

#include "tcp_socket.h"

void handle_file(int fd_client)
{	
	MSG message,snd_msg;
	int read_n;
	memset(&message,0,sizeof(message));
	recv(fd_client,&message,MSG_LEN,0);
	recv(fd_client,&message.s_buf,message.s_len,0);
	printf("recv msg:%s\n",message.s_buf);
	int fd_file = open(message.s_buf,O_RDONLY);
	while(memset(&snd_msg,0,sizeof(snd_msg)),(read_n = read(fd_file,snd_msg.s_buf,MSG_SIZE))>0 )
	{
		snd_msg.s_len = read_n;
		send(fd_client,&snd_msg,snd_msg.s_len+MSG_LEN,0);
	}
	snd_msg.s_len = 0;
	send(fd_client,&snd_msg,snd_msg.s_len+MSG_LEN,0);
	close(fd_file);
}

