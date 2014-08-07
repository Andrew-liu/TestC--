#include "Handle.h"
#include "Animal.h"

Handle::Handle()
    :ptr_(NULL)
{
}

Handle::Handle(const Animal &a)
    :ptr_(a.copy()) /* 这里通过引用触发了多态 */
{
}

Handle::Handle(const Handle &other)
    :ptr_(other.ptr_->copy())
{
}

Handle::~Handle()
{
    delete ptr_;
}

Handle &Handle::operator=(const Handle &other)
{
    if(this != &other)
    {
        delete ptr_;
        ptr_ = other.ptr_->copy();
    }

    return *this;
}


Animal *Handle::operator->()
{
    return ptr_;
}
const Animal *Handle::operator->() const
{
    return ptr_;
}
