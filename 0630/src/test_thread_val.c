/*************************************************************************
	> File Name: test_thread_val.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 30 Jun 2014 04:13:47 PM HKT
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
int cnt = 0;
pthread_mutex_t my_mutex;
void *my_hand(void *arg)//cnt放在内存里
{
	int i;
	for(i = 0;i<10000;++i)
	{
		pthread_mutex_lock(&my_mutex);
		cnt++;
		pthread_mutex_unlock(&my_mutex);
	}
}
int main()
{
	pthread_mutex_init(&my_mutex,NULL);
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,my_hand,NULL);
	pthread_create(&tid2,NULL,my_hand,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("the cnt is %d\n",cnt);
	pthread_mutex_destroy(&my_mutex);

}
