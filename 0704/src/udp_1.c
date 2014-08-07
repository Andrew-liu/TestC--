/*************************************************************************
	> File Name: udp_1.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:55:12 AM HKT
 ************************************************************************/

#include "UDP_socket.h"

int main(int argc,char *argv[])
{
	char recv_buf[1024];
	struct sockaddr_in recv_client;
	int len_client;
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	int fd_socket = udp_init(argv[1],atoi(argv[2]));
	while(1)//echo server
	{
		bzero(recv_buf,1024);
		bzero(&recv_client,sizeof(recv_client));
		len_client = sizeof(recv_client);
		recvfrom(fd_socket,recv_buf,1024,0,(struct sockaddr *)&recv_client,&len_client);
		if( strcmp( inet_ntoa(recv_client.sin_addr),"192.168.1.52" ) ==0 )
		{
			char *aa = "撸乐，清女神的bug好调么？";
	    	sendto(fd_socket,aa,strlen(aa),0,(struct sockaddr*)&recv_client,sizeof(recv_client));
			continue;
				
		}
		printf("The host %s:%d Msg: %s\n",inet_ntoa(recv_client.sin_addr),ntohs(recv_client.sin_port),recv_buf);
		sendto(fd_socket,recv_buf,strlen(recv_buf),0,(struct sockaddr*)&recv_client,sizeof(recv_client));
	}

}
