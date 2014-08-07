#ifndef _MYRUN_
#define _MYRUN_

#include "ProduceThread.h"
#include "ConsumeThread.h"
#include "Buffer.h"
#include <iostream>
using namespace std;

class Myrun
{
    public:
        Myrun(int size);
        ~Myrun();
        void run();
    private:
        Buffer buffer_;
        ProduceThread pro_;
        ConsumeThread con_;  
};

Myrun::Myrun(int size)
            :buffer_(size),
            pro_(buffer_),
            con_(buffer_)
{
    pro_.run();
    con_.run();
}
Myrun::~Myrun()
{
    pro_.join();
    con_.join();
}
void Myrun::run()
{
    pro_.start();
    con_.start();
}
#endif
