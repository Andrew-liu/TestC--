#include "thread.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void add(void *arg)
{
    int t = (int)arg;
    cout << t * t << endl;
}



int main(int argc, const char *argv[])
{
    ThreadPool pool(100);
    pool.Create();
    srand(100);
    while(1)
    {
        sleep(1);
        Task task;
        task.SetData((void *)(rand() % 100));
        pool.AddTask(&task);
    }
    pool.StopAll();
    return 0;
}
