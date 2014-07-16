#ifndef _CONSUME_
#define _CONSUME_

#include <pthread.h>

#include "Buffer.h"

class ConsumeThread
{
    public:
        ConsumeThread(Buffer &buffer);

        void start();
        static void *ThreadFunc(void *arg);
        void run();
        void join();

    private:
        pthread_t tid_;
        Buffer    &buffer_;
};

#endif
