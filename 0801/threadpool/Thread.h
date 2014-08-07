#ifndef _PTHREAD_
#define _PTHREAD_

#include <iostream>
#include <string.h>
#include <pthread.h>
#include <string>
#include <unistd.h>

#define BOOL int 
#define FALSE 0
#define TRUE 1

class Task
{
    public:
        void (*callback_)(void *);
        void *arg;
};

class Node
{
    public:
        Task data;
        Node *next;
};

class Queue
{
    public:
        Queue();
        Queue(size_t size);
        ~Queue();
        void push(Task task);
        void pop();
        Task top();
        void clear();
        BOOL isempty();
        size_t getsize();
    private:
        Node *head_;
        Node *tail_;
        size_t size_;
};

class ThreadPool
{
    public:
        ThreadPool(size_t size);
        ~ThreadPool();
        void pthread_start();
        void pthread_stop();
        static void *pthread_func(void *arg);
        void pthread_add_task(Task task);
        BOOL pthread_get_task(Task &task);
        BOOL pthread_is_start();
        size_t pthread_get_size();
    private:
        size_t size_;
        pthread_t *pthreads_;
        pthread_mutex_t mutex_;
        pthread_cond_t cond_;
        Queue Q_;
        BOOL flag_;

};
#endif
