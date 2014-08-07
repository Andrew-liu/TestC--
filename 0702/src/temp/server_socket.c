/*************************************************************************
	> File Name: server_socket.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 03:53:31 PM HKT
 ************************************************************************/
/*
 * 1. 建立socket文件 int socket()//ipv4,stream,0
 * 2. 绑定相关描述(ip & port) int bind(),初始化sockaddr_in结构体，ip/port转为网络字节序,//htons(),inet_addr()
 * 3. 设置监听状态，初始化监听队列int listen()
 * 4. 服务器从监听队列中取连接，int accept,通过其返回值建立新的socket来与客户端通信（阻塞函数），保存客户端的socket信息
 * 5. 与客户端收发信息ssize_t recv(),ssize_t sent()
 * 6. 退出
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#define PORT 8888
#define IP   "192.168.1.69"
#define SIZE 1024

int main(int argc,char *argv[])
{
	signal(13,SIG_IGN);
	int fd_server = socket(AF_INET,SOCK_STREAM,0);
	if( -1 == fd_server )
	{
		perror("socket error\n");
		exit(-1);
	}
	struct sockaddr_in sock_server;
	struct in_addr ip_server;
	sock_server.sin_family = AF_INET;
	sock_server.sin_port  = htons(PORT);
	sock_server.sin_addr.s_addr  = inet_addr(IP);

	if( -1 == bind(fd_server,(struct sockaddr*)&sock_server,sizeof(sock_server)) )
	{
		perror("bind error\n");
		exit(-1);
	}

	if( -1 == listen(fd_server,5) )
	{
		perror("listen error\n");
		exit(-1);
	}

	struct sockaddr_in sock_work_server;
	socklen_t client_len=0;
	printf("begin accept\n");
	int fd_work_server = accept(fd_server,(struct sockaddr*)&sock_work_server,&client_len);
	if( -1 == fd_work_server )
	{
		perror("accept error\n");
		exit(-1);
	}
	char recv_buf[1024]="";
	int nread,total;
	int n_recv;
//	char *pbuf = recv_buf;
	while( memset(recv_buf,0,1024),recv(fd_work_server,recv_buf,1024,0)>0 )
	{
		printf("from client %s message:%s\n",inet_ntoa(sock_work_server.sin_addr),recv_buf);
	//	for( total = 0; total < SIZE;)
	//	{
	//		n_recv = recv(fd_work_server,recv_buf,SIZE,0);
			send(fd_work_server,recv_buf,strlen(recv_buf),0);
	//		if( n_recv == 0)
	//			break;
	//		if( n_recv == -1)
	//			break;
	//	total += n_recv;
	//	pbuf  += n_recv;
	}
//	}
	//	send(fd_work_server,recv_buf,strlen(recv_buf),0);
	//	printf("sent to client %s message:%s\n",inet_ntoa(sock_work_server.sin_addr),recv_buf);
//	}
	printf("recv = %d\n",recv);
	close(fd_server);
	close(fd_work_server);
	return 0;
}

