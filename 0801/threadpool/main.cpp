#include "Thread.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void task_func(void *arg)
{
    int i = (int)arg;
    cout << i++ <<endl;
}

int main(int argc, const char *argv[])
{
    ThreadPool pool(4);
    pool.pthread_start();
    srand(100);
    while(1)
    {
        sleep(1);
        Task task;
        task.callback_ = task_func;
        task.arg = (void *)(rand()%100);
        pool.pthread_add_task(task);
    }
    return 0;
}
