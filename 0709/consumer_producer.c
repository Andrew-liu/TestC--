#include "queue.h"
#define BUFFERSIZE 5

Queue Q; //定义一个队列
sem_t full;//同步信号量,用于表示缓冲区产品的个数
sem_t empty;//同步信号量,用于表示缓冲区的用于生产的空闲区域的个数
pthread_mutex_t mutex; //互斥信号量, 用于对缓冲区的互斥

void *producer(void *arg)
{
    while(1)
    {
        //p()
        sem_wait(&empty);//生产者查看有没有生产空间,进入缓冲区生产产品
        pthread_mutex_lock(&mutex);
        
        int num=rand()%100;
        queue_push(&Q,num);
        printf("producer num is %d\n",num);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

 void *consumer(void *arg)
{
    while(1)
    {
        sem_wait(&full);//消费者查看有没有产品,然后进入缓冲区
        pthread_mutex_lock(&mutex);
        
        int num=queue_top(&Q);
        printf("consumer num is %d\n",num);
        queue_pop(&Q);


        pthread_mutex_unlock(&mutex);
        sem_post(&empty);//v()
        sleep(3);
    }
}
int main(int argc, const char *argv[])
{
    srand(time(NULL));
    pthread_t tid1,tid2;
    sem_init(&full,0,0);//对同步信号量初始化full = 0; empty = BUFFERSIZE;
    sem_init(&empty,0,BUFFERSIZE);
    pthread_mutex_init(&mutex,NULL);//初始化同步信号量.
    queue_init(&Q);//初始化队列


    pthread_create(&tid1,NULL,producer,NULL);
    pthread_create(&tid2,NULL,consumer,NULL);
    pthread_join(tid1,NULL);//回收线程资源
    pthread_join(tid2,NULL);

    queue_clear(&Q);//销毁队列
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
