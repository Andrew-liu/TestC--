#ifndef _BUFFER_
#define _BUFFER_

#include "MutexLock.h"
#include "Condition.h"
#include "Queue.h"
#include <pthread.h>

class Buffer
{
    public:
        Buffer(size_t size);
        ~Buffer();
        void Produce(int data);
        void Consume();
    private:
        Queue queue_;
        MutexLock mutex_;
        Condition empty_;
        Condition full_;
        size_t size_;
};

#endif
