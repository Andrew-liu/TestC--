#ifndef _PTHREADPOOL_
#define _PTHREADPOOL_

#include "NonCopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include <iostream>
#include <vector>
#include <functional>
#include <pthread.h>
#include <queue>

class Thread;

class ThreadPool
{
    public:
        typedef std::function< void ()> Task;

        ThreadPool(size_t queuesize, size_t poolsize);
        ~ThreadPool();

        void start();
        void stop();
        void addtask(const Task &);
        Task gettask();
    private:
        void run(); //线程池的回调函数

        MutexLock mutex_;
        Condition empty_;
        Condition full_;
        size_t queuesize_;
        std::queue<Task> queue_;
        size_t poolsize_;
        std::vector<Thread *> threads_;//线程池
        bool flag_;//开启状态

};

#endif
