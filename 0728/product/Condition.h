#ifndef _CONDITION_
#define _CONDITON_

#include "MutexLock.h"
#include <pthread.h>

class Condition
{
    public:
        Condition(MutexLock &);
        ~Condition();

        void Wait();
        void Notify();
        void NotifyAll();
    private:
        pthread_cond_t cond_;
        MutexLock &mutex_;

};

#endif
