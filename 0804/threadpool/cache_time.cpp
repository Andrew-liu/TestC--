#include "ThreadPool.h"
#include "Timer.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <functional>
using namespace std;

class TimePool
{
    friend class Timer ;
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
        cout << "hello world " << s_ << endl;
    }
    void runcallback()
    {
        time_.Settime(1, 3);
        time_.Setcallback(bind(&TimePool::cache, this));
        pool_.addTask(bind(&Timer::Run, &time_));
        while(1)
        {
            s_ = "hello bady";
            pool_.addTask(bind(&TimePool::print, this));
            sleep(1);
        }
    } 
    private:
    void cache()
    {
        cout << "hello world" << endl;
    }
    ThreadPool pool_;
    Timer time_;
    string s_;
};

int main(int argc, const char *argv[])
{
    TimePool pool(4,5);
    pool.runcallback();
    return 0;
}
