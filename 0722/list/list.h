#ifndef __LIST__
#define __LIST__

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
class List
{
    public:
        List();
        List(const List &);
        List &operator = (const List &);
        ~List();

        void Insert(Node<T> *pt, const T &value);
        void Delete(Node<T> *pt);
        void Reset(Node<T> *pt,const T &value);
        bool IsEmpty();
        Node<T> *End();
        Node<T> *find(const T &value);
        void destroy();
    private:
        Node<T> *head_;
        Node<T> *end_;
};
template <class T>
Node<T> *List<T>::End()
{
    return end_;
}

template <class T>
inline List<T>::List()
    :head_(NULL),
     end_(NULL)
{}

template <class T>
inline List<T>::List(const List &other)
    :head_(NULL),
     end_(NULL)
{
    for(Node<T> *pt = other.head_; pt != NULL; pt = pt->next)
    {
        insert(pt->data);
    }
}

template <class T>
inline List<T> &List<T>::operator = (const List &other)
{
    if(this != &other)
    {
        delete head_;
        delete end_;
        head_ = other.head_;
        end_ = other.end_;
    }
    return *this;
}

template <class T>
inline List<T>::~List()
{
    destroy();
}

template <class T> //将元素插入到pt后面,为空的时候就是第一个节点
inline void List<T>::Insert(Node<T> *pt, const T &value)
{
    Node<T> *cur = new Node<T>;
    cur->data = value;
    cur->next = NULL;
    if(IsEmpty())
    {
        head_ = end_ = cur;
    }
    else
    {
        cur->next = pt->next;
        pt->next = cur;
    }
    if(pt == end_)
    {
        end_ = cur;
    }
}

template <class T>
inline void List<T>::Delete(Node<T> *pt)
{
    Node<T> cur = head_;
    while(cur != pt  && cur != NULL && cur->next != pt)
    {//找到前驱
        cur = cur->next;
    }
    if(cur != NULL)
    {
        if(pt != end_)
        {
            cur = cur->next->next;
            free(pt);
        }
        else
        {
            end_ = cur;
            free(pt);
        }
    }
    else
    {
        throw std::out_of_range("Delete");
    }
}

template <class T>
inline void List<T>::Reset(Node<T> *pt, const T &value)
{
    Node<T> *cur = head_;
    while(cur != NULL && cur != pt)
    {
        cur = cur->next;
    }
    if(cur != NULL)
    {
        cur->data = value;
    }
    else
    {
        throw std::out_of_range("Reset");
    }
}

template <class T>
inline bool List<T>::IsEmpty()
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
inline Node<T> *List<T>::find(const T &value)
{
    Node<T> *pre = head_;
    while(pre && pre->data != value)
    {
        pre = pre->next;
    }
    return pre;
}

template <class T>
inline void List<T>::destroy()
{
    if(head_ != NULL)
    {
        Delete(end_);
    }
}
#endif     
