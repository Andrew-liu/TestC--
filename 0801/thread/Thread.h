#ifndef _THREAD_H_
#define _THREAD_H_

#include <iostream>
#include <string>
#include <pthread.h>
#include <functional>

class Thread
{
    public:
        Thread();
        Thread(void *(*callback)(void *));
        ~Thread();
        void create();
        void join();
    private:
        void *(*callback_)(void *);
        //std::function<void *(void *)> callback_;
        pthread_t tid_;
};


#endif
