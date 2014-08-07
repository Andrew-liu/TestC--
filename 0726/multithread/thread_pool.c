#include "thread.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pthread_init(pool_t *pool, size_t size)
{
    pool->size_ = size;
    pool->pthreads_ =(pthread_t *)malloc(size * sizeof(pthread_t));
    pthread_mutex_init(&pool->mutex_, NULL);
    pthread_cond_init(&pool->cond_, NULL);
    queue_init(&pool->Q_);
    pool->flag_ = FALSE;
}

void pthread_destroy(pool_t *pool)
{   
    pthread_stop(pool);
    free(pool->pthreads_);
    pthread_mutex_destroy(&pool->mutex_);
    pthread_cond_destroy(&pool->cond_);
    queue_destroy(&pool->Q_);
}

void *pthread_func(void *arg)
{
    pool_t *pool = (pool_t *)arg;
    while(1)
    {
        task_t task; //用于获取任务
        BOOL ret = pthread_get_task(pool, &task);
        if(ret = TRUE)
        {
            task.thread_callback(task.arg);
        }
        else
        {
            break; //线程结束
        }
    }
   return NULL; 
}

void pthread_start(pool_t *pool)
{
    if(pool->flag_ == FALSE)
    {
        pool->flag_ = TRUE;

        int i;
        for(i = 0; i < pool->size_; ++i)
        {
            pthread_create(&pool->pthreads_[i], NULL, pthread_func, pool);
        }
    }
}

void pthread_stop(pool_t *pool)
{
    if(pool->flag_ == FALSE)
    {
        return ;
    }
    pool->flag_ = FALSE;
    pthread_cond_broadcast(&pool->cond_);//激活所有阻塞的线程 ??????????
    int i; 
    for(i = 0; i < pool->size_; ++i)
    {
        pthread_join(pool->pthreads_[i], NULL);
    }
}

void pthread_add_task(pool_t *pool, task_t tsk)
{
    pthread_mutex_lock(&pool->mutex_);
    queue_push(&pool->Q_, tsk);//生产一个任务 唤醒消费者
    pthread_cond_signal(&pool->cond_);
    pthread_mutex_unlock(&pool->mutex_);
}

BOOL pthread_get_task(pool_t *pool, task_t *task)//将取出的任何放入task
{
    pthread_mutex_lock(&pool->mutex_);
    while(is_empty(&pool->Q_) == TRUE && pool->flag_ ==TRUE ) //?????????
    {
        pthread_cond_wait(&pool->cond_, &pool->mutex_);
    }

    if(pool->flag_ == FALSE)
    {
        pthread_mutex_unlock(&pool->mutex_);  //???????????????
        return FALSE;
    }
    *task = queue_top(&pool->Q_);
    queue_pop(&pool->Q_);
    pthread_mutex_unlock(&pool->mutex_);
    return TRUE;
}

BOOL pthread_is_start(pool_t *pool)
{
    if(pool->flag_ == TRUE)
        return TRUE;
    else
        return FALSE;
}

size_t pthread_get_size(pool_t *pool)
{
    return pool->size_;
}
