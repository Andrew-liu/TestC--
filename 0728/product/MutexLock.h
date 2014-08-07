#ifndef _MUTEXLOCK_
#define _MUTEXLOCK_

#include <pthread.h>

class MutexLock
{
    public:
        MutexLock();
        ~MutexLock();

        void Lock();
        void UnLock();
        pthread_mutex_t *GetLock();
    private:
        pthread_mutex_t mutex_;

};

#endif
