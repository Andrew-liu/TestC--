#include "Buffer.h"
#include <stdlib.h>
#include <iostream>


Buffer::Buffer(size_t size)
    :queue_(),
     mutex_(),
     empty_(mutex_), //mutex_要传入到cond_变量里
     full_(mutex_),
     size_(size)
{}

Buffer::~Buffer()
{}

void Buffer::Produce(int data)
{
    mutex_.Lock();
    while(queue_.getSize() >= size_) //没有生产空间
    {
        empty_.Wait();
    }
    
    queue_.push(data);
    std::cout << "the produce is " << data <<std::endl;
    full_.Notify();
    mutex_.UnLock();
}

void Buffer::Consume()
{
    mutex_.Lock();
    while(queue_.isEmpty())
    {
        full_.Wait();
    }
    int data = queue_.top();
    queue_.pop();
    std::cout << "the consume is " << data <<std::endl;
    empty_.Notify();
    mutex_.UnLock();

}

