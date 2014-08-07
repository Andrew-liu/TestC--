/*************************************************************************
	> File Name: read_first.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 30 Jun 2014 07:59:25 PM HKT
 ************************************************************************/
/*
 * 1.当写者出现后，后来的读者被堵塞，直到没有写者
   2.第一个读者和写者竞争
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define NUM 10
#define filename "./a.txt"
pthread_mutex_t m_access;//use for mutex critical
pthread_mutex_t m_write_num;//use for mutex read_num
int write_num = 0;
char buf[1024];
void *read_hand(void * arg)
{
	FILE *fp_rd = fopen(filename,"rb");
	pthread_detach(pthread_self());
	pthread_mutex_lock(&m_access);
	pthread_mutex_lock(&m_write_num);
	if( write_num != 0)
	{
		printf("a reader start!!\n");
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
		pthread_mutex_unlock(&m_access);
	}
		pthread_mutex_unlock(&m_write_num);
		fclose(fp_rd);
//	sleep(3);
}
void *write_hand(void * arg )
{
	pthread_detach( pthread_self());
	pthread_mutex_lock(&m_write_num);
	if( 0 == write_num )
	{
		pthread_mutex_lock(&m_access);
	}
	pthread_mutex_unlock(&m_write_num);

	pthread_mutex_lock(&m_write_num);
	++write_num;
	pthread_mutex_unlock(&m_write_num);

	pthread_mutex_lock( &m_access );
	FILE *fp_wr = fopen(filename,"a");
	printf("a writer start\n");
	if( NULL == fp_wr )
	{
		perror("write error\n");
		exit(-1);
	}
	pthread_mutex_unlock( &m_access );

	pthread_mutex_lock(&m_write_num);
	--write_num;
	pthread_mutex_unlock(&m_write_num);
	
	pthread_mutex_lock(&m_write_num);
	if( 0 == write_num )
	{
		pthread_mutex_unlock(&m_access);
	}
	pthread_mutex_unlock(&m_write_num);
	fclose(fp_wr);
}


int main()
{
	int i =1 ;
	pthread_mutex_init(&m_access,NULL);
	pthread_mutex_init(&m_write_num,NULL);
	srand(getpid());
	while(1)
	{
		i++;
		if( i % 2  != 0 )//reader
		{
			pthread_t tid;
			pthread_create(&tid,NULL,read_hand,NULL);
		}
		else
		{
			pthread_t tid;
			pthread_create(&tid,NULL,write_hand,NULL);
		}
	}
	pthread_mutex_destroy(&m_access);
	pthread_mutex_destroy(&m_write_num);

}


