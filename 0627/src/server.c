/*************************************************************************
	> File Name: server.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 27 Jun 2014 03:24:12 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
/*
 *
 * 1.服务器打开“上线管道”读端，若有客户端上线，则开始运行
 *
 * 2.select循环检测
 *
 * 3.检测“上线管道”，发现有客户端上线，通过其客户端pid，得到读写管道名（注意客户端读端是服务器的写端）。打开读写管道，判断
 *	 客户端表是否满，若未满，将上线的客户端读，写描述符填入客户端表，并将其纳入集合 
 *
 * 4.检测“读写管道”，从客户端发送管道读端拿到其发送的信息，判断是不是bye（下线）,若是bye，则将其从监听集合和客户端列表中删 *   掉。若不是bye，则将得到信息转发到所有上线的客户端
 */
#define num 500
typedef struct tag
{
	int fd_read;
	int fd_write;
}client_info;
int main(int argc,char *argv[])
{
	int fd_write,fd_read,fd_login_rd ;
	int count = 0;
	client_info tag[num];
	char read_name_fifo[128] = "";
	char write_name_fifo[128]= "";
	char buf[32]  = "";
	char buf_client[1024]="";
	struct timeval t;
	memset(tag,0,num*sizeof(client_info));
	fd_login_rd = open(argv[1],O_RDONLY);
	printf("OK1\n");
	if( -1 == fd_login_rd )
	{
		perror("open error\n");
		exit(-1);
	}
	fd_set read_set,ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd_login_rd,&read_set);
	while(1)
	{
	//	memset(tag,-1,sizeof(tag));
		t.tv_sec = 0;
		t.tv_usec = 1000;//1 ms
		ready_set = read_set;
		if(-1 == select(1024,&ready_set,NULL,NULL,&t) )
		{
			perror("error\n");
			exit(-1);
		}
		if( FD_ISSET(fd_login_rd,&ready_set) )
		{
			printf("hello word\n");
			pid_t pid_client;
			memset(buf,0,32);
			if( read(fd_login_rd,buf,32) == 0)
				continue;
			puts(buf);
			pid_client = (pid_t)atoi(buf); 
			sprintf(read_name_fifo,"%d_send.fifo",atoi(buf));
			puts(read_name_fifo);
			sprintf(write_name_fifo,"%d_receive.fifo",atoi(buf));
			puts(write_name_fifo);
		//	int fd_read  = open(read_name_fifo,O_RDONLY);
			fd_write = open(write_name_fifo,O_WRONLY);
		    fd_read  = open(read_name_fifo,O_RDONLY);
			if( -1 == fd_read)
			{
				perror("11\n");
			}
		//	int fd_write = open(write_name_fifo,O_WRONLY);
			printf("fd_write=%d\n",fd_write);
			printf("OK2\n");
			int i_isfull;//use for judge fd_table full 
			for( i_isfull = 0 ; i_isfull < num; ++i_isfull)
			{
	//			printf("OK\n");
				if( tag[i_isfull].fd_read == 0 )
					break;
			}
			if( i_isfull < num )//fd_table is not full
			{

				printf("OK3!!!\n");
				tag[i_isfull].fd_read  = fd_read;
				tag[i_isfull].fd_write = fd_write;
				++count;
				printf("OK4\n");
		//		FD_SET(fd_read,&ready_set);
			//	FD_SET(fd_write,&ready_set);
			}
			else//fd_table is full -> end client 
			{
			//	printf("OK\n");
				kill(pid_client,0);
				close(fd_write);
				close(fd_read);
				unlink(write_name_fifo);
				unlink(read_name_fifo);
			}
			printf("GGGG11\n");
			FD_SET(fd_read,&read_set);
			printf("GGGG22\n");
		//	ready_set = read_set;
		}
		int i_is_wr;// use for judge the client write  
		for(i_is_wr =0; i_is_wr < num; ++i_is_wr)
		{
		//	printf("OK5\n");
			if( FD_ISSET(tag[i_is_wr].fd_read,&ready_set) )
			{
		//		char buf_client[1024]="";
				memset(buf_client,0,1024);
				printf("OK6\n");
				read(tag[i_is_wr].fd_read,buf_client,1024);
				if(strncmp( buf_client,"bye",3) !=0 )//send message to all client
				{
					printf("OK7\n");
					int i_send;
					for(i_send =0; i_send < num; ++i_send )
					{
						printf("OK8\n");
						if(tag[i_send].fd_write != 0)
						{
							write(tag[i_send].fd_write,buf_client,strlen(buf_client));
						}
					}
				}
				else
				{
					printf("OK9\n");
					printf("a clinet off\n");
					close(tag[i_is_wr].fd_read);
					close(tag[i_is_wr].fd_write);
					FD_CLR(tag[i_is_wr].fd_read,&read_set);
	//				FD_CLR(fd_login_rd,&ready_set);
					tag[i_is_wr].fd_read  = 0;
					tag[i_is_wr].fd_write = 0; 
				}


			}
		}
//	}

}

}

