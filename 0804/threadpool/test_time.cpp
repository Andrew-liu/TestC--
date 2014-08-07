#include "ThreadPool.h"
#include "Timer.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <functional>
using namespace std;

class TimePool
{
    public:
        TimePool(size_t queuesize, size_t poolsize):pool_(queuesize, poolsize)
        {
            pool_.start();
        }
        ~TimePool()
        {
            pool_.stop();
        }
        void print()
        {
            cout << "hello world" << endl;
        }
        void runcallback()
        {
            time_.Settime(1, 3);
            time_.Setcallback(bind(&TimePool::print, this));
            while(1)
            {
                pool_.addTask(bind(&Timer::Run, &time_));
            }
        }

        
    private:
        ThreadPool pool_;
        Timer time_;
};

int main(int argc, const char *argv[])
{
    TimePool pool(4,5);
    pool.runcallback();
    return 0;
}
