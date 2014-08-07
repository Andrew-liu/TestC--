#include "def.h"
#include <stdlib.h>
#include <pthread.h>



/*
typedef struct{
    size_t size_;   //线程池大小
    pthread_t *pthreads_;   //线程数组
    BOOL is_started_;        //pool是否开启
    queue task_queue_;      //任务队列
    pthread_mutex_t mutex_; //互斥锁
    pthread_mutex_t cond_;  //条件变量， 用于通知消费者取任务
} pool_t;
*/

void thread_pool_init(pool_t *pool, size_t size)
{
    pool->size_ = size;
    pool->pthreads_ = (pthread_t *)malloc(sizeof(pthread_t) * pool->size_);
    pool->is_started_ = FALSE;
    queue_init(&pool->queue_);
    pthread_mutex_init(&pool->mutex_, NULL);
    pthread_cond_init(&pool->cond_, NULL);
}
void thread_pool_destroy(pool_t *pool) //销毁线程池
{
    thread_pool_stop(pool);
    free(pool->pthreads_);
    queue_destroy(&pool->queue_);
    pthread_mutex_destroy(&pool->mutex_);
    pthread_cond_destroy(&pool->cond_);
}


void *thread_pool_thread_func(void *arg)
{
    //从线程池中取任务
    pool_t *pool = (pool_t *)arg;
    while(1)
    {
        task_t task;
        BOOL ret = thread_pool_get_task_from_queue(pool, &task);
        if(ret == TRUE)  
            task.thread_callback(task.arg);//执行任务
        else
            break;  //获取任务失败，说明线程池已经关闭
    }
}


void thread_pool_start(pool_t *pool)   //启动线程池
{
    if(pool->is_started_ == FALSE)
    {
        pool->is_started_ = TRUE;
        int i;
        for(i = 0; i < pool->size_; ++i)
        {
            pthread_create(&pool->pthreads_[i], NULL, thread_pool_thread_func, pool);
        }
    }
}

void thread_pool_stop(pool_t *pool)    //停止
{
    if(pool->is_started_ == FALSE) // 已经关闭
        return ;
    pool->is_started_ = FALSE;
    //激活所有等待任务的线程
    //假设有10个线程，一个任务
    //会有9个阻塞
    //
    pthread_cond_broadcast(&pool->cond_);  
    
    int i;
    for(i = 0; i < pool->size_; ++i)
    {
        pthread_join(pool->pthreads_[i], NULL);
    }
    queue_clear(&pool->queue_);
}

void thread_pool_add_task_to_queue(pool_t *pool, task_t task) //添加任务
{
    pthread_mutex_lock(&pool->mutex_);
    queue_push(&pool->queue_, task);
    pthread_cond_signal(&pool->cond_);
    pthread_mutex_unlock(&pool->mutex_);
}

//获取任务成功，返回TRUE，任务放在task里面
//否则返回FALSE
BOOL thread_pool_get_task_from_queue(pool_t *pool, task_t *task) //取任务
{
    pthread_mutex_lock(&pool->mutex_);
    while(queue_is_empty(&pool->queue_) == TRUE && pool->is_started_ == TRUE)
        //这里被唤醒有两种
        //任务到来，被signal唤醒
        //线程池关闭，被broadcast唤醒
        pthread_cond_wait(&pool->cond_, &pool->mutex_);

    //说明线程池被关闭
    //上面的wait是被broadcast唤醒的
    if(pool->is_started_ == FALSE)
    {
        pthread_mutex_unlock(&pool->mutex_);
        return FALSE;
    }
    *task = queue_top(&pool->queue_);
    queue_pop(&pool->queue_);

    pthread_mutex_unlock(&pool->mutex_);
    return TRUE;
}


BOOL thread_pool_is_started(const pool_t *);    //是否开启
size_t thread_pool_get_size_of_queue(const pool_t *);   //任务队列大小


