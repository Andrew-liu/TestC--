#include "thread.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void task_func(void *arg)
{
    int t = (int)arg;
    printf("%d\n" ,t * t );
}

int main(int argc, const char *argv[])
{ 
    pool_t pool; //如果定义为指针需要给指针开辟空间
    pthread_init(&pool, 4);
    pthread_start(&pool);
    srand(100);
    while(1)
    {
        sleep(1);
        task_t task;
        task.thread_callback = task_func;
        task.arg = (void *)(rand() % 100);
        pthread_add_task(&pool, task);
    }

    pthread_stop(&pool);
    pthread_destroy(&pool);
    return 0;
}
