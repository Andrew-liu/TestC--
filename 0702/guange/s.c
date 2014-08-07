/*************************************************************************
	> File Name: s.c
	> Author: GWG_BHB
	> Mail:gaowenguang123@gmail.com 
	> Created Time: Wed 02 Jul 2014 01:41:15 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define IP "192.168.1.69"
#define PORT 6666
void * thread(void * arg)
{

}
int main()
{
	int fd_server,fd_client;
	struct sockaddr_in sock_addr;
	fd_server=socket(AF_INET,SOCK_STREAM,0);
	if(fd_server==-1)
	{
		perror("ERROR:");
		exit(-1);
	}
	sock_addr.sin_family=AF_INET;
	sock_addr.sin_port=htons(PORT);
	sock_addr.sin_addr.s_addr=inet_addr(IP);
   if( bind(fd_server,(struct sockaddr *)&sock_addr,sizeof(sock_addr))==-1)
   {
	   perror("bind:");
	   close(fd_server);
	   exit(-1);
   }
   listen(fd_server,6);
   struct sockaddr_in * client_addr;
   int len=sizeof(client_addr);
   while(1)
   {
   fd_client=accept(fd_server,(struct sockaddr *)&client_addr,&len);
   char recv_buff[1024];
   char send_buff[1024];
   memset(recv_buff,0,1024);
   recv(fd_client,recv_buff,1024,0);
    printf("message recv\n");
	if((chdir(recv_buff)==0))    //文件夹
	{
		DIR *dir;
		struct dirent *dir_ent;
		dir=opendir(recv_buff);
		while((dir_ent=readdir(dir))!=NULL)
		{
			memset(send_buff,0,1024);
			sprintf(send_buff,"%s",dir_ent->d_name);
			send(fd_client,send_buff,strlen(send_buff),0);
			printf("%s\n",send_buff);
		}
		strcpy(send_buff,"bye");
		send(fd_client,send_buff,strlen(send_buff),0);
	}
	else
	{
		 int find;                          //这是文件
		 if((find=open(recv_buff,O_RDONLY))==-1)  //打开失败
		 {
			 perror("open error:");
			 exit(-1);
		 }
		 int recv_n;
		 while(memset(send_buff,0,1024),(recv_n=read(find,send_buff,1024))>0)
		 {
			 send(fd_client,send_buff,recv_n,0);
		 }
		 printf("over.......\n");
	}
   }
   close(fd_client);
   close(fd_server);
	return 0;
}
