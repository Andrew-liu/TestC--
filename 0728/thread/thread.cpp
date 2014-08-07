#include "thread.h"
#include <pthread.h>
#include <stdexcept>

std::vector<Task *> ThreadPool::task_list_;

ThreadPool::ThreadPool(size_t size)
    :thread_num_(size),
     flag_(FALSE),
     pthreads_(new pthread_t[size])
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cond_, NULL);
}

ThreadPool::~ThreadPool()
{
    StopAll();
    delete pthreads_;
    pthread_mutex_destroy(&mutex_);
    pthread_cond_destroy(&cond_);
}

void *ThreadPool::ThreadFunc(void *arg)
{
    std::cout << "come" << std::endl;
    ThreadPool *pool = static_cast<ThreadPool *>(arg);
    while(1)
    {
        Task *task = new Task;
        BOOL ret = pool->GetTask(task);
        if(ret == TRUE)
        {
            task->Run();
        }
        else
        {   
            break;
        }
    }
    return NULL;
}

//static int MoveToIdle(pthread_t tid);
//static int MoveToBusy(pthread_t tid);       

void ThreadPool::Create()
{
  //  std::cout << "create" << std::endl;
    if(flag_ == FALSE)
    {
        flag_ = TRUE;
        for(int i = 0; i != thread_num_; ++i)
        {
            pthread_create(&pthreads_[i], NULL, ThreadFunc, this );
        }
    }
}
void ThreadPool::AddTask(Task *task)
{
//    std::cout << "add" << std::endl;
    pthread_mutex_lock(&mutex_);
    this->task_list_.push_back(task);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}

BOOL ThreadPool::GetTask(Task *task)
{
    pthread_mutex_lock(&mutex_);
    while(TaskIsEmpty() == TRUE && flag_ ==TRUE)
    {
        pthread_cond_wait(&cond_, &mutex_);
    }
    if(flag_ == FALSE)
    {
        pthread_mutex_unlock(&mutex_);
        return FALSE;
    }
//    std::cout << "gettask" << std::endl;
    std::vector<Task *>::iterator it = task_list_.begin();
    if(it != task_list_.end())
    {
        task = *it;
        task_list_.erase(it);
    }
    pthread_mutex_unlock(&mutex_);
    return TRUE;
}

BOOL ThreadPool::TaskIsEmpty()
{
    if(thread_num_ == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void ThreadPool::StopAll()
{
    if(flag_ == FALSE)
        return ;
    flag_ =TRUE;
    
    pthread_cond_broadcast(&cond_);

    for(int i = 0; i != thread_num_; ++i)
    {
        pthread_join(pthreads_[i], NULL);
    }
}

size_t ThreadPool::GetTaskSize()
{
    return thread_num_;
}

