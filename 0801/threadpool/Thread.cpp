#include "Thread.h"

Queue::Queue():head_(NULL),
               tail_(NULL),
               size_(0)
{}

Queue::Queue(size_t size):head_(NULL),
                          tail_(NULL),
                          size_(size)
{}

Queue::~Queue()
{
    clear();
}

void Queue::push(Task task)
{
    Node *cur = new Node;
    cur->data = task;
    cur->next = NULL;
    if(isempty())
    {
        head_ = tail_ = cur;
    }
    else
    {
        tail_->next = cur;
        tail_ = cur;
    }
    ++size_;
}

void Queue::pop()
{
    Node *cur = head_;
    head_ = head_->next;
    delete cur;
    --size_;
}

Task Queue::top()
{
    return head_->data;
}

void Queue::clear()
{
    if(!isempty())
    {
        pop();
    }
}

BOOL Queue::isempty()
{
    if(head_ == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

size_t Queue::getsize()
{
    return size_;
}


ThreadPool::ThreadPool(size_t size):size_(size),
          Q_(0),
          flag_(FALSE)
{
    pthreads_ =new pthread_t[size];
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cond_, NULL);
}

ThreadPool::~ThreadPool()
{
    pthread_stop();
    delete [] pthreads_;
    pthread_mutex_destroy(&mutex_);
    pthread_cond_destroy(&cond_);
}

void *ThreadPool::pthread_func(void *arg)
{
    ThreadPool *thread = static_cast<ThreadPool *>(arg);
    while(1)
    {
        Task task;
        BOOL ret = thread->pthread_get_task(task);
        if(ret == TRUE)
        {
            task.callback_(task.arg);
        }
        else
        {
            break;
        }
    }
    return NULL;
}

void ThreadPool::pthread_start()
{
    if(flag_ == FALSE)
    {
        flag_ =TRUE;
        int i;
        for(i = 0; i < size_; ++i)
        {
            pthread_create(&pthreads_[i], NULL,pthread_func, (void *)this);
        }
    }
}

void ThreadPool::pthread_stop()
{
    if(flag_ == FALSE)
    {
        return ;
    }
    flag_ =FALSE;
    pthread_cond_broadcast(&cond_);
    int i;
    for(i = 0; i < size_; ++i)
    {
        pthread_join(pthreads_[i],NULL);
    }

}

void ThreadPool::pthread_add_task(Task task)
{
    pthread_mutex_lock(&mutex_);
    Q_.push(task);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}

BOOL ThreadPool::pthread_get_task(Task &task)
{
    pthread_mutex_lock(&mutex_);
    while(flag_ == TRUE && Q_.isempty() == TRUE)
    {
        pthread_cond_wait(&cond_, &mutex_);
    }
    
    if(flag_ == FALSE)
    {
        pthread_mutex_unlock(&mutex_);
        return FALSE;
    }
    task = Q_.top();
    Q_.pop();
    pthread_mutex_unlock(&mutex_);
    return TRUE;
}


BOOL ThreadPool::pthread_is_start()
{
    if(flag_ == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

size_t ThreadPool::pthread_get_size()
{
    return size_;
}

