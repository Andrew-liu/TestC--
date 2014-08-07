#ifndef _THREAD_
#define _THREAD_

#include <iostream>
#include <functional>
#include <pthread.h>

class Thread
{
    public:
        typedef std::function< void ()> Threadfunc;
        Thread(Threadfunc callback);
        ~Thread();

        void start();
        void join();
    private:
        static void *threadfunc(void *);

        pthread_t  tid_;
        bool       isstart_;
        Threadfunc callback_;
};

#endif


