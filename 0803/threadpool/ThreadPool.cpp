#include "ThreadPool.h"
#include "Thread.h"

using namespace std;

ThreadPool::ThreadPool(size_t queuesize, size_t poolsize)
    :empty_(mutex_),
     full_(mutex_),
     queuesize_(queuesize),
     poolsize_(poolsize),
     flag_(false)
{}

ThreadPool::~ThreadPool()
{
    if(flag_ == false)
    {
        stop();
    }
}

void ThreadPool::addtask(const Task &task)
{
    mutex_.lock();
    while(queue_.size() >= queuesize_) // 没空位生产,坐等
    {
        empty_.wait();
    }
    queue_.push(task);
    full_.notify();
    mutex_.unlock();
    
}

ThreadPool::Task ThreadPool::gettask()
{
    mutex_.lock();
    while(queue_.empty() && flag_ ==true)
    {
        full_.wait();//没任务了,坐等生产
    }
    Task task;
    if(!queue_.empty()) //这个不是空的时候才进入函数体
    {
        task = queue_.front();
        queue_.pop();
        empty_.notify();
    }
    mutex_.unlock();
    return task;
}


void ThreadPool::run()//真正的处理任务
{
    while(flag_ == true)
    {
        Task task = gettask();
        if(task)
        {
            task();
        }
    }
}
void ThreadPool::start()
{
    if(flag_ == true)
    {
        return ;
    }
    flag_ =true;
    for(size_t i = 0; i != poolsize_; ++i)//任务放入进程池
    {
        threads_.push_back(new Thread(bind(&ThreadPool::run, this)));
    }
    for(size_t i = 0; i != poolsize_; ++i)
    {
        threads_[i]->start();
    }
}

void ThreadPool::stop()
{
    if(flag_ == false)
        return ;
    mutex_.lock();
    flag_ == false;
    full_.notifyAll();
    mutex_.unlock();
    for(size_t i = 0; i < poolsize_; ++i)
    {
        threads_[i]->join();
    }
    while(!queue_.empty())
    {
        queue_.pop();
    }

}
