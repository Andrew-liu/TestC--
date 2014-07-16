#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <assert.h>
//队列的结构体定义
typedef struct q_node
{
    int data;
    struct q_node *next;
}q_node,*p_node;

typedef struct 
{
    p_node head;
    p_node tail;
    size_t size;
}Queue;

void queue_init(Queue *Q);
void queue_push(Queue *Q,int data);
void queue_pop(Queue *Q);
int queue_top(Queue *Q);
int queue_empty(Queue *Q);
void queue_clear(Queue *Q);//清空操作
int queue_size(Queue *Q);

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#endif
