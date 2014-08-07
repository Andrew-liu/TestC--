/*************************************************************************
  > File Name: udp_process_pool.c
  > Author: Suqing
  > Mail:116676671@qq.com 
  > Created Time: Sat 05 Jul 2014 03:32:23 PM HKT
 ************************************************************************/

#include "udp_process_pool.h"

int main(int argc,char *argv[])
{
	if( 4 != argc )//exe,ip,port,cnt
	{
		perror("argc error\n");
		exit(-1);
	}
	//init udp socket
	int fd_server = udp_init(argv[1],atoi(argv[2]));
	//init struct tag
	int pro_num = atoi(argv[3]);
	pChild p = (pChild)calloc(pro_num,sizeof(Child));
	//create process_pool
	int max_pro_fd = make_process_pool(pro_num,p);
	printf("OK123\n");
	//init fd_set
	fd_set read_set,ready_set;
	struct timeval t;
	FD_ZERO(&read_set);
	FD_SET(fd_server,&read_set);
	int index;
	for( index =0;index < pro_num;++index)
	{
		FD_SET(p[index].fd_read,&read_set);
	}
	int max_fd = max_pro_fd>fd_server?max_pro_fd:fd_server;

	//start select
	while(1)
	{
		t.tv_sec  = 0;
		t.tv_usec = 1000;
		ready_set = read_set;
		if( -1 == select(max_fd+1,&ready_set,NULL,NULL,&t) )
		{
			perror("selcet error\n");
			exit(-1);
		}
		//		printf("AAAAAAA\n");
		//detect client
		if( FD_ISSET(fd_server,&ready_set) )
		{
		//	printf("OK1\n");
			char filename[128];
			bzero(filename,128);
			SA client_addr;
			bzero(&client_addr,sizeof(SA));
			int client_len = sizeof(SA);
			recvfrom(fd_server,filename,128,0,(struct sockaddr*)&client_addr,&client_len);
			printf("The host %s:%d connected..\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
			int index;
			for(index = 0;index < pro_num;++index)
			{
				if( S_IDLE == p[index].flag )
					break;
			}
			p[index].flag = S_BUSY;
			p[index].cnt++;
			FILE *fp_wr = fdopen(p[index].fd_write,"w");
			if( NULL == fp_wr )
			{
				perror("open error\n");
				exit(-1);
			}
			fprintf(fp_wr,"%s %d %s",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),filename);
			fflush(fp_wr);
		//	fclose(fp_wr);
		}
		int index;
		for(index =0;index<pro_num;++index)
		{
	//		printf("OK1\n");
			char opt;
			if( FD_ISSET(p[index].fd_read,&ready_set) )
			{
				printf("OK2\n");
				read(p[index].fd_read,&opt,1);
				p[index].flag = S_IDLE;
			}
		}

	}
}
