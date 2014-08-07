#include "handle.h"
#include "animal.h"

Handle::Handle():ptr_(NULL)
{}

Handle::Handle(const Animal &other)
    :ptr_(other.copy())   //引用触发多态
{}

Handle::Handle(const Handle &other)
    :ptr_(other.ptr_ ->copy())
{}

Handle::~Handle()
{
    delete ptr_;
}

Handle &Handle::operator = (const Handle & other)
{
    if(this != &other)
    {
        delete ptr_;
        ptr_ = other.ptr_ ->copy();
    }
    return *this;
}

Animal *Handle::operator -> ()
{
    return ptr_;
}

const Animal *Handle::operator -> () const
{
    return ptr_;
}
