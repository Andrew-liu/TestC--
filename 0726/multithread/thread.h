#ifndef __PTHREAD_
#define __PTHREAD_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define BOOL int
#define FALSE 0
#define TRUE  1

typedef struct
{
    void (*thread_callback)(void *);
    void *arg;

}task_t;

typedef struct Node
{
    task_t data;
    struct Node *next;
}Node,*pNode;

typedef struct
{
    pNode head_;
    pNode tail_;
    size_t size_;
}Queue;

typedef struct
{
    size_t size_;
    pthread_t *pthreads_;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
    Queue Q_;
    BOOL flag_;
}pool_t;

void queue_init(Queue *);
void queue_destroy(Queue *);
void queue_push(Queue *, task_t);
void queue_pop(Queue *);
task_t queue_top(Queue *);
void queue_clear(Queue *);
BOOL is_empty(Queue *);
size_t get_size(Queue *);

void pthread_init(pool_t *, size_t);
void pthread_destroy(pool_t *);
void pthread_start(pool_t *);
void pthread_stop(pool_t *);
void pthread_add_task(pool_t *, task_t);
BOOL pthread_get_task(pool_t *, task_t *);
BOOL pthread_is_start(pool_t *);
size_t pthread_get_size(pool_t *);

#endif 
