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

        void Push(T data);
        void Pop();
        T    Top();
        bool IsEmpty();
        void Clear();
        size_t  Size();
        void Debug();
    private:
        Node<T> *head_;
        Node<T> *tail_;
        size_t   size_;
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
    Clear();
}

template <class T>
inline void Queue<T>::Push(T data)
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
inline void Queue<T>::Pop()
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
inline T Queue<T>::Top()
{
    if(!IsEmpty())
    {
        return head_->data;
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
inline void Queue<T>::Clear()
{
    if(!IsEmpty())
    {
       Pop();
    }
}
template <class T>
inline size_t Queue<T>::Size()
{
    return size_;
}

template <class T>
inline void Queue<T>::Debug()
{
    Node<T> *p = head_;
    while(p)
    {
        std::cout << p->data <<" ";
        p = p->next;
    }
    std::cout << std::endl;
}
#endif
