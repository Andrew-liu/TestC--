#ifndef THREAD_H_
#define THREAD_H_ 

#include <pthread.h>

class Thread
{
    public:
        virtual ~Thread(){}

        void start();
        static void *threadFunc(void *);
        virtual void run();
        void join();

    private:
        pthread_t tid_;
};

#endif  /*THREAD_H_*/
