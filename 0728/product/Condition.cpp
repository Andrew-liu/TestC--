#include "Condition.h"

Condition::Condition(MutexLock &mutex):mutex_(mutex)
{
    pthread_cond_init(&cond_, NULL);
}

Condition::~Condition()
{
    pthread_cond_destroy(&cond_);
}

void Condition::Wait()
{
    pthread_cond_wait(&cond_, mutex_.GetLock());
}

void Condition::Notify()
{
    pthread_cond_signal(&cond_);
}

void Condition::NotifyAll()
{
    pthread_cond_broadcast(&cond_);
}
