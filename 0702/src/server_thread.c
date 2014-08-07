/*************************************************************************
	> File Name: server_thread.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 10:06:14 AM HKT
 ************************************************************************/

#include "tcp_socket.h"

void *my_hand(void *arg)
{
	pthread_detach(pthread_self());
	int fd_client = (int)arg;
	handle_file(fd_client);
}


int main()
{
	signal(13,SIG_IGN);
	int fd_server = tcp_init();
	int fd_client;// = tcp_accpet(fd_server);
	while( (fd_client = tcp_accept(fd_server)) )
	{
		pthread_t tid;
		pthread_create(&tid,NULL,my_hand,(void *)fd_client);
	}
	close(fd_client);
	return 0;
}
