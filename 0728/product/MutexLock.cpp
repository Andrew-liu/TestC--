#include "MutexLock.h"
#include <pthread.h>

MutexLock::MutexLock()
{
    pthread_mutex_init(&mutex_, NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&mutex_);
}

void MutexLock::Lock()
{
    pthread_mutex_lock(&mutex_);
}

void MutexLock::UnLock()
{
    pthread_mutex_unlock(&mutex_);
}

pthread_mutex_t *MutexLock::GetLock()
{
    return &mutex_;
}

