#ifndef THREAD_H_
#define THREAD_H_ 

#include "NonCopyable.h"
#include <pthread.h>

class Thread : private NonCopyable
{
    public:

        typedef void *(* ThreadFunc) (void *);

        Thread(ThreadFunc func);
        ~Thread();

        void start();
        void join();

    private:
        ThreadFunc callback_;
        pthread_t tid_;
        bool isStarted_;  //是否在运行
};


#endif  /*THREAD_H_*/
