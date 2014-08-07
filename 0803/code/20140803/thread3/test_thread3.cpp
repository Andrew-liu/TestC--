#include "Thread.h"
#include <iostream>
using namespace std;


class FooThread
{
    public:
        FooThread(int i);
        void threadFunc();
        void startThread();
        void joinThread();

    private:
        int cnt_;
        Thread thread_; //类的组合
};


FooThread::FooThread(int i)
    :cnt_(i),
     thread_(bind(&FooThread::threadFunc, this))
{
}

void FooThread::threadFunc()
{
    while(1)
    {
        sleep(1);
        cout << "cnt = " << cnt_++ << endl;
    }
}

void FooThread::startThread()
{
    thread_.start();
}

void FooThread::joinThread()
{
    thread_.join();
}


int main(int argc, const char *argv[])
{
    FooThread foo(34);
    foo.startThread();


    foo.joinThread();


    return 0;
}
