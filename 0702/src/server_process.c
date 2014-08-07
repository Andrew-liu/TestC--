/*************************************************************************
	> File Name: server_process.c
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
		
		if( fork() == 0 )
		{
			handle_file(fd_client);
		}
	}

}
