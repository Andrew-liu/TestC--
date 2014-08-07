#include "thread.h"

Thread::Thread(Threadfunc callback)
    :tid_(0),
     isstart_(false),
     callback_(callback)
{}

Thread::~Thread()
{
    if(isstart_)
    {
        pthread_detach(tid_);
    }
}

void *Thread::threadfunc(void *arg)
{
    Thread *T = static_cast<Thread *>(arg);
    T->callback_();
}

void Thread::start()
{
        pthread_create(&tid_, NULL, threadfunc, (void *)this);
}

void Thread::join()
{
        pthread_join(tid_, NULL);
}
