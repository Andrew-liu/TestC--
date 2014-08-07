#include "Thread.h"

Thread::Thread():tid_(0)
{}

Thread::Thread(void *(*callback)(void *)):tid_(0),callback_(callback)
{}

Thread::~Thread()
{}

void Thread::create()
{
    pthread_create(&tid_, NULL,callback_, NULL);
}

void Thread::join()
{
    pthread_join(tid_, NULL);
}
