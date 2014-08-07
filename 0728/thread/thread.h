#ifndef __THREAD__
#define __THREAD__

#include <iostream>
#include <string>
#include <vector>

#define BOOL int
#define FALSE 0
#define TRUE 1

class Task
{
    friend class ThreadPool;
    private:
        void *arg;
    public:
        Task() {}
        ~Task(){}
        void Run()
        {
            std::cout << (int)arg << std::endl;
            sleep(2);
        }
        void SetData(void *data)
        {
            arg = data;
        }
};

class ThreadPool
{
    private:
        static std::vector<Task *> task_list_;
        BOOL flag_;
        size_t thread_num_;
        pthread_t *pthreads_;
        pthread_mutex_t mutex_;
        pthread_cond_t cond_;

    public:
        ThreadPool(size_t size);
        ~ThreadPool();

        static void *ThreadFunc(void *arg);


        void Create();
        void AddTask(Task *task);
        BOOL GetTask(Task *task);
        BOOL TaskIsEmpty();
        void StopAll();
        size_t GetTaskSize();
};

#endif
