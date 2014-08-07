/*************************************************************************
	> File Name: getdate.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 07 Jul 2014 04:46:18 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
//获取任意主机的日期和时间	
int main(int argc,char *argv[])
{
	struct hostent *hostinfo;
	struct servent *servinfo;
	struct sockaddr_in host_addr;
	char buf[128];
	char *host;

	if( 1 == argc )
	{
		host = "localhost";
	}
	else
	{
		host = argv[1];
	}
	hostinfo = gethostbyname(host);
	if( !hostinfo )
	{
		perror("error");
		exit(-1);
	}
	servinfo = getservbyname("daytime","tcp");
	if( !servinfo )
	{
		perror("error");
		exit(-1);
	}
	printf("daytime port is %d\n",ntohs(servinfo->s_port));
	int fd = socket(AF_INET,SOCK_STREAM,0);
	host_addr.sin_family = AF_INET;
	host_addr.sin_port   = htons(servinfo->s_port);
	host_addr.sin_addr   = *(struct in_addr *)*hostinfo->h_addr_list;
	int len = sizeof(host_addr);
	connect(fd,(struct sockaddr *)&host_addr,len);
	int result = read(fd,buf,128);
	buf[result] = '\0';
	printf("read %d bytes:%s\n",result,buf);
	close(fd);
	return 0;
}

