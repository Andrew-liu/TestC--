/*************************************************************************
	> File Name: tcp_process_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 08 Jul 2014 02:42:03 PM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

int main(int argc,char *argv[])
{
	int work_socket;
	if( 4 != argc )
		ERR_EXIT("argc error");
	int fd_server = tcp_init(argv[1],atoi(argv[2]));
	//init process 
	int pro_num   = atoi(argv[3]); 
	pChild_info p = (pChild_info)calloc(pro_num,sizeof(Child_info));
	int max_read_fd = make_process(p,pro_num);
	//init fd_set
	fd_set read_set,ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd_server,&read_set);
	int index;
	for( index=0;index<pro_num; ++index)
	{
		FD_SET(p[index].fd_read,&read_set);
	}
	struct timeval t;

	//start select
	int max_fd = max_read_fd>fd_server ? max_read_fd : fd_server; 
	while(1)
	{
		t.tv_sec  = 0;
		t.tv_usec = 1000;
		ready_set = read_set;
		if( -1 == select(max_fd+1,&ready_set,NULL,NULL,&t) )
			ERR_EXIT("select error");
		if( FD_ISSET(fd_server,&ready_set) )
		{
			work_socket = tcp_accept(fd_server);
			//find idle process
			int index;
			for(index = 0;index < pro_num;++index)
			{
				if( S_IDLE == p[index].status )
					break;
			}
			p[index].status = S_BUSY;
			p[index].count++;
			close(p[index].fd_read);
			send_describe(p[index].fd_write,work_socket);
		//	printf("OK\n");
		}
		int index;
		for(index = 0;index<pro_num;++index)
		{
			if( FD_ISSET(p[index].fd_read,&ready_set) )
			{
				int re_status;
				FILE *fp_rd = fdopen(p[index].fd_read,"r");
				if( NULL == fp_rd )
					ERR_EXIT("fdopen error");
				fscanf(fp_rd,"%d",&re_status);
				if( 0 == re_status )
					p[index].status = S_IDLE;
			}
		}

	}

}
