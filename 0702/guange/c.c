/*************************************************************************
	> File Name: c.c
	> Author: GWG_BHB
	> Mail:gaowenguang123@gmail.com 
	> Created Time: Wed 02 Jul 2014 04:19:19 AM PDT
 ************************************************************************/

#include<stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SERVER_PORT 6666
#define SERVER_IP "192.168.1.69" 
int main()
{
	int fd_client;
	struct sockaddr_in server_addr;

	memset(&server_addr,0,sizeof(server_addr));
	fd_client=socket(AF_INET,SOCK_STREAM,0);
    if(fd_client==-1)
	{
		perror("SOCKET_ERROR:");
		exit(-1);
	}
     server_addr.sin_family=AF_INET;
	 server_addr.sin_port=htons(SERVER_PORT);
	 server_addr.sin_addr.s_addr=inet_addr(SERVER_IP);
	int i= connect(fd_client,(struct sockaddr *)&server_addr,sizeof(server_addr));
     if(i==-1)
	 {
		 perror("CONNECT:");
		 exit(-1);
	 }
	 char i_buff[128];
	 char o_buff[1024];
	 int recv_n;
	 printf("请输入要查询的文件或者目录......\n");
	scanf("%s",i_buff);
	 send(fd_client,i_buff,strlen(i_buff),0);
	 while(1)
	 {
		 memset(o_buff,0,1024);
		 //recv_n=recv(fd_client,o_buff,1024,0);
		 recv_n=read(fd_client,o_buff,sizeof(o_buff));
//		 printf("recv_n = %d\n",recv_n);
		 printf("%s\n",o_buff);
		 if(0 == strncmp(o_buff,"bye",3) )
		 {
			 break;
		 }
	 }
	 printf("输出完毕......\n");
     close(fd_client);
     return 0;
}
