/*************************************************************************
	> File Name: producer_consumer_2.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 01 Jul 2014 04:17:44 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define NUM 20

typedef struct queue
{
	int data[NUM];
	int front;//queue head use for read
	int rear;//queue tail use for write
	pthread_mutex_t m_critial;
	phtread_cond_t no_empty;//no empty can read
	phtread_cond_t no_full;//no full can write
}Sq_queue,*pQueue;

void init_queue(pQueue *q)
{
	memset((*q)->data,0,NUM);
	(*q)->front = 0;
	(*q)->rear  = 0 ;
	pthread_mutex_init(&( (*q)->m_critial),NULL  );
	pthread_cond_init (&( (*q)->no_empty),NULL );
	pthread_cond_init (&( (*q)->no_full),NULL );
}
int is_empty(pQueue q)//0为队空
{
	int len = (q->rear - q->front+NUM)%NUM;
	if( 0 == len )
		return 0;
	else
		return len;
}
void enQueue(pQueue *q,int data)//生产者入队
{
	pthread_mutex_lock( &(*q)->m_critial );
	while( ((*q)->rear+1) % NUM == (*q)->front )//队满
	{
		printf("wait for not full\n");
		pthread_cond_wait( &((*q)->no_full),&( (*q)->m_critial) );
	}

	(*q)->data[(*q)->rear] = data;
	(*q)->rear++;
	if( (*q)->rear >= NUM  )//循环队列，若写指针写到最后就转到开头
		(*q)->rear = 0;
	pthread_cond_signal(&(*q)->no_empty);

	pthread_mutex_unlock(&(*q)->m_critial);
}

void deQueue(pQueue *q,int *data)//消费者出队
{
	pthread_mutex_lock(&(*q)->m_critial);
	while((*q)->rear == (*q)->front )//队空
	{
		printf("wait for queue not empty\n");
		pthread_cond_wait(&(*q)->no_empty,&(*q)->m_critial);
	}
	*data = (*q)->data[(*q)->front];
	(*q)->front++;
	if((*q)->front >= NUM )
		(*q)->front = 0;
	pthread_cond_signal(&(*q)->no_full);
	pthread_mutex_unlock(&(*q)->m_critial);
}
void destroy_queue(pQueue *q)
{
	pthread_mutex_destory(&(*q)->m_critial);
	pthread_cond_destory(&(*q)->no_full);
	pthread_cond_destory(&(*q)->no_empty);
}
void *producer(void *arg)
{
	enQueue
}



pQueue buf;
int main(int argc,char *argv[])
{
	init_queue(&buf);
	pthread_t producer,consumer1,consumer2;
	pthread_create(&producer,NULL,producer,NULL);
	pthread_create(&consumer1,NULL,consumer,NULL);
	pthread_create(&consumer2,NULL,consumer,NULL);

	pthread_join(&producer,NULL);
	pthread_join(&consumer1,NULL);
	pthread_join(&consumer2,NULL);

	destory_queue(&buf);
	



}
