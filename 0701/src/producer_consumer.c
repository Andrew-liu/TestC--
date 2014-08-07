/*************************************************************************
	> File Name: producer_consumer.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 01 Jul 2014 10:21:26 AM HKT
 ************************************************************************/

/*
 * 生产者与消费者问题
 * 1. 生产车间是应该定义为循环队列
 * 2.一个互斥锁用于互斥访问临界区，两个条件，一个是消费者等待临界区不空，一个是生产者等待临界区不满，因此设计两个计数left_cnt,product_cnt加上两把锁
 * 3.生产者从队头操作，消费者从队尾操作
 *
 * 生产者逻辑：
 * 1. 生产者判断临界区是否满，若满则阻塞等待，不能进入临界区
 * 2. 若不满，访问临界区，开始生产，改变计数。此时当临界区从空到不空时要通知消费者，让消费者解除堵塞
 *    塞（pthread_cond_signal)
 * 3. 生产者生产完了要睡一会，防止生产者一直抢着生产
 *
 * 消费者逻辑：
 * 1.消费者判断临界区是否空，若空则阻塞等待，不能进入临界区
 * 2.若不空，访问临界区，开始消费，改变计数。此时当临界区从满到不满是要通知生产者，让生产者解除堵塞
 * 3.消费者消费完了睡一会，防止一直抢着消费

 * 
 *
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/*typedef struct queue//queue for buf
{

}*/
int empty ;
int full  ;

pthread_mutex_t m_critical;
pthread_mutex_t m_empty;//the number of empty space
pthread_mutex_t m_full;//the number of used space

pthread_cond_t cond_consumer;
pthread_cond_t cond_producer;

void *my_producer(void *arg)

{
	while(1)
	{		
		pthread_mutex_lock(&m_critical);
		while( 0 == empty )
		{
			pthread_cond_wait( &cond_producer,&m_critical);
		}
	
		printf("a producer start,current product is %d\n",full);

		++full;
		if( 1 == full )
		{
			pthread_cond_broadcast(&cond_consumer);
		}

		--empty;
	//	sleep(rand()%5+1);

		printf("a producer end,current product is %d\n",full);
	//	sleep(1);
		sleep(rand()%5+1);

		pthread_mutex_unlock( &m_critical);
	}
}
void *my_consumer(void *arg )
{
	while(1)
	{
		pthread_mutex_lock(&m_critical);
		while( 0 == full )
		{
			pthread_cond_wait(&cond_consumer,&m_critical);
		}
		printf("a consumer start the product is %d\n",full);
		++empty;
		if( 1 == empty )
		{
			pthread_cond_broadcast(&cond_producer);
		}
		--full;
	//	sleep(rand()%5+1);

		printf("a consumer end the product is %d\n",full);
	//	sleep(1);
		pthread_mutex_unlock(&m_critical);
		sleep(rand()%5+1);
	}
}


int main(int argc,char *argv[])
{
	empty = 20;
	full = 0;
	srand(getpid());
	pthread_mutex_init(&m_critical,NULL);
	pthread_mutex_init(&m_empty,NULL);
	pthread_mutex_init(&m_full,NULL);
	pthread_cond_init(&cond_consumer,NULL);
	pthread_cond_init(&cond_producer,NULL);

	pthread_t producer,consumer1,consumer2;
	pthread_create(&producer,NULL,my_producer,NULL);
	pthread_create(&consumer1,NULL,my_consumer,NULL);
	pthread_create(&consumer2,NULL,my_consumer,NULL);


	pthread_join(producer,NULL);
	pthread_join(consumer1,NULL);
	pthread_join(consumer2,NULL);
	

	pthread_mutex_destroy(&m_critical);
	pthread_mutex_destroy(&m_empty);
	pthread_mutex_destroy(&m_full);
	pthread_cond_destroy(&cond_consumer);
	pthread_cond_destroy(&cond_producer);


}
