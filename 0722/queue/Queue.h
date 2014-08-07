#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <stdexcept>
template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;
};

template <class T>
class Queue
{   
    public:
        Queue();
        Queue(const Queue &);
        Queue &operator = (const Queue &);
        ~Queue();

        void push(T data);
        void pop();
        T  top();
        bool IsEmpty();
        void clear();
        size_t  size();
    private:
        Node<T> *head_;
        Node<T> *tail_;
        size_t size_;
};

template <class T>
inline Queue<T>::Queue()
   :head_(NULL),
    tail_(NULL),
    size_(0)
{}

template <class T>
inline Queue<T>::Queue(const Queue &other)
    :head_(NULL),
     tail_(NULL),
     size_(0)
{
    for(Node<T> *pt = other.head_; pt != other.tail_; ++pt)
    {
        push(pt->data);
    }
}

template <class T>
inline Queue<T> &Queue<T>::operator = (const Queue &other)
{
    if(this != &other)
    {
        delete head_;
        delete tail_;
        head_ = new Node<T>(*other.head_);
        tail_ = new Node<T>(*other.tail_);
        size_ = other.size_;
    }
    return *this;
}

template <class T>
inline Queue<T>::~Queue()
{
    clear();
}

template <class T>
inline void Queue<T>::push(T data)
{
    Node<T> *pre = new Node<T>;
    pre->data = data;
    pre->next = NULL;
    if(head_ ==NULL)
    {
        head_ = tail_ = pre;
    }
    else
    {
        tail_->next = pre;
        tail_ = pre;
    }
    ++size_;
}

template <class T>
inline void Queue<T>::pop()
{
    if(!IsEmpty())
    {
        Node<T> *pre = head_;
        head_ = head_->next;
        delete pre;
        --size_;
    }
    else
    {
        throw std::out_of_range("pop");
    }
}

template <class T>
inline T Queue<T>::top()
{
    if(!IsEmpty())
    {
        return tail_->data;
    }
    else
    {
        throw std::out_of_range("top");
    }
}

template <class T>
inline bool Queue<T>::IsEmpty()
{
    if(head_ == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
inline void Queue<T>::clear()
{
    if(!IsEmpty())
    {
        pop();
    }
}
template <class T>
inline size_t Queue<T>::size()
{
    return size_;
}
#endif
