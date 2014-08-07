#include "smartpoint.h"
#include <iostream>
using namespace std;

Smartpoint::Smartpoint():ptr_(NULL)
{
}

Smartpoint::Smartpoint(Animal *ptr)
    :ptr_(ptr)
{
}

Smartpoint::~Smartpoint()
{
    delete ptr_;
}

void Smartpoint::reset(Animal *ptr)
{
    if(ptr != ptr_) //不是自身的改变
    {
        delete ptr_;
        ptr_ = ptr; //使原来的指针指向形参的内存
    }
}
const Animal *Smartpoint::getptr() const
{
    return ptr_;
}
Animal &Smartpoint::operator * ()
{
    return *ptr_;
}
Animal *Smartpoint::operator -> ()
{
    return ptr_;
}

int main(int argc, const char *argv[])
{
    Smartpoint smart(new Animal);
    smart.reset(NULL);
    Smartpoint smart1(new Animal);

    return 0;
}

