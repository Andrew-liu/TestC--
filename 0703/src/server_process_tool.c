/*************************************************************************
	> File Name: server_process_tool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 07:24:46 PM HKT
 ************************************************************************/

/*  进程池通信过程
 *  1.定义结构体(pid,status,fd_read,fd_write,r_cnt)，记录处理请求进程（儿子进程）的状态
 *  2.初始化服务器socket。创建含有n个进程的进程池，并且初始化每个进程的结构体。
 *  3.初始化进程：创建管道(2对匿名或者命名)用于与父进程进行读写操作；子进程重定向管道，处理逻辑需求，父进程初始化结构体、 初始化读写管道
 *  4.select 监听客户端以及子进程，监听客户端，accopet将描述符
 *
 */
#include "tcp_socket.h"

int main(int argc,char *argv[])
{

	int fd_work_server;
	if( 4 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	int fd_server;

	//init process struct
	pChild_info p =(pChild_info)malloc(atoi(argv[3])*sizeof(Child_info));
	memset(p,0,sizeof(p));
	int max_fd = make_process(p,atoi(argv[3]));

	 fd_server = tcp_init(argv[1],atoi(argv[2])); 
	printf("fd_server %d\n",fd_server);
	//init fd_set
	fd_set read_set,ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd_server,&read_set);
	int i;
	for( i=0;i<atoi(argv[3]);++i)
	{
		FD_SET(p[i].fd_read,&read_set);
	}
	struct timeval t;

	//start select 
	while(1)
	{
		t.tv_sec  = 0;
		t.tv_usec = 1000;
		ready_set = read_set;
		if( -1 == select(1024,&ready_set,NULL,NULL,&t) )
		{
			perror("select error\n");
			exit(-1);
		}
		if(FD_ISSET(fd_server,&ready_set) )
		{
			// fd_work_server = accept(fd_server,NULL,NULL);
			fd_work_server = tcp_accept(fd_server);
			int i;
			for(i=0;i<atoi(argv[3]);++i)
			{
				if(p[i].status == S_IDLE )
				{
					break;
				}
			}
			if(i == atoi(argv[3]))
			{
				//动态创建
			}
			else
			{
				p[i].status = S_BUSY;
				++p[i].s_cnt
		//	fd_wr = open(p[i].fd_write,O_WRONLY);
			printf("i = %d\n",i);
			FILE *fp_wr = fdopen(p[i].fd_write,"w");
			printf("open OK\n");
			fprintf(fp_wr,"%d",fd_work_server);
			fflush(fp_wr);
			}
		}
		int i;
		for(i=0;i<atoi(argv[3]);++i)
		{
	//		printf("OK2\n");
			if( FD_ISSET(p[i].fd_read,&ready_set) )
			{
				int re_status;
				// fd_rd = open(p[i].fd_read,O_RDONLY);
				FILE *fp_rd = fdopen(p[i].fd_read,"r");
				printf("OK888\n");
				fscanf(fp_rd,"%d",re_status);
				printf("re_status = %d\n",re_status);
				if( re_status == 1 )
				p[i].status = S_IDLE;
			}
		}
	//	close(fd_wr);
	//	fclose(fp_wr);
	//	close(fd_work_server);
	}
	return 0;
}

