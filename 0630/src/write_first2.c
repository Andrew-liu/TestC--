/*************************************************************************
	> File Name: read_first.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 30 Jun 2014 07:59:25 PM HKT
 ************************************************************************/
/*
 * 读者写者问题：读者优先
 * 1.任意多的线程可以同时读文件
 * 2.一次只允许一个写线程往文件中写
 * 3.如果一个写线程正在写，禁止任何其他读写线程访问文件
 * 4.写线程操作前，必须让所有的读线程退出
 * 5.在读者读文件时，对随后到达的读者和写者，首先满足读者
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define filename "./a.txt"
pthread_mutex_t m_access;//use for mutex critical
pthread_mutex_t m_read_num;//use for mutex read_num
pthread_mutex_t is_write;
int read_num = 0;
char buf[1024];
void *read_hand(void * arg)
{
	pthread_detach(pthread_self());

	pthread_mutex_lock( &is_write);
	pthread_mutex_unlock( &is_write );

	pthread_mutex_lock(&m_read_num);
	if( read_num == 0 )
	{
		pthread_mutex_lock(&m_access );
	}
	pthread_mutex_unlock(&m_read_num);
	
	pthread_mutex_lock(&m_read_num);
	++read_num;
	pthread_mutex_unlock(&m_read_num);

	printf("a reader start!!\n");
	FILE *fp_rd = fopen(filename,"rb");
	if( NULL == fp_rd )
	{
		perror("read error\n");
		exit(-1);
	}
	char buf_read[1024];
	while( memset(buf_read,0,1024),fgets(buf_read,1024,fp_rd) != NULL)
	{
		fputs(buf_read,stdout);
	}
	sleep(3);
	pthread_mutex_lock(&m_read_num);
	--read_num;
	if( 0 == read_num )
	{
		pthread_mutex_unlock(&m_access);
	}
	pthread_mutex_unlock( &m_read_num );
	fclose(fp_rd);
//	sleep(3);
}
void *write_hand(void * arg )
{
	pthread_detach(pthread_self());
	FILE* fp_wr = fopen(filename,"a");
	pthread_mutex_lock( &is_write );
	pthread_mutex_lock( &m_access);
	printf("a write start!!\n");
	if( NULL == fp_wr )
	{
		perror("write error\n");
		exit(-1);
	}
	char buf[1024];
	while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL )
	{
		fprintf(fp_wr,"%s",buf);
		fflush(fp_wr);
	}		
	sleep(3);
	pthread_mutex_unlock( &m_access );
	pthread_mutex_unlock( &is_write );
	fclose(fp_wr);
//	sleep(3);
}


int main()
{
	int i =1 ;
	pthread_mutex_init(&m_access,NULL);
	pthread_mutex_init(&m_read_num,NULL);
	pthread_mutex_init(&is_write,NULL);
	srand(getpid());
	while(1)
	{
	//	i = rand()%100;		
//		printf("i =%d\n",i);
	//	i++;
		if( i % 2  != 0)//reader
		{
			pthread_t tid;
			pthread_create(&tid,NULL,read_hand,NULL);
		}
		else
		{
			pthread_t tid;
			pthread_create(&tid,NULL,write_hand,NULL);
			sleep(5);
		}
		++i;
	}
	pthread_mutex_destroy(&m_access);
	pthread_mutex_destroy(&m_read_num);
	pthread_mutex_destroy(&is_write);

}


