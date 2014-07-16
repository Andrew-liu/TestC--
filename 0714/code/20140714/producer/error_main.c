#include "queue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0);

#define BUFFERSIZE 5

pthread_mutex_t mutex; //互斥锁，保护队列
pthread_cond_t full;    //同步量，代表有产品可拿
pthread_cond_t empty;  //同步量，代表可以放入
Queue Q;  //缓冲区队列

void *producer(void *arg){
    while(1){
        sleep(5);
        pthread_mutex_lock(&mutex);
        if(queue_get_size(&Q) >= BUFFERSIZE){
            //队列满
            pthread_cond_wait(&empty, &mutex);
        }
        //生产操作
        int data = rand() % 100;
        queue_push(&Q, data);
        printf("procuder a data : %d\n", data);
        //pthread_cond_signal(&full);  /* 通知消费者 */
        pthread_cond_broadcast(&full);
        pthread_mutex_unlock(&mutex);

    }
}

void *consumer(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(queue_is_empty(&Q)){
            printf("wait producer\n");
            pthread_cond_wait(&full, &mutex);
        }
        //消费操作
        int data = queue_top(&Q);
        queue_pop(&Q);
        printf("consume a data: %d\n", data);

        pthread_cond_signal(&empty); /* 通知生产者  */
        pthread_mutex_unlock(&mutex);
    }
}


int main(int argc, const char *argv[])
{
    srand(13242);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);
    queue_init(&Q);


    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_create(&t3, NULL, consumer, NULL);
    pthread_create(&t4, NULL, consumer, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);



    queue_destroy(&Q);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    pthread_mutex_destroy(&mutex);
    return 0;
}
