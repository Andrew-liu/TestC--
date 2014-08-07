#ifndef __LIST__
#define __LIST__

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

template <class T>
class Node
{
    public:
        Node(T e):data(e),next(NULL),pre(NULL)
        {}
        T data;
        Node<T> *next;
        Node<T> *pre;
};

template <class T>
class List
{
    public:
        List();
        ~List();
        bool IsEmpty();//判断是否为空
        int GetLength();//获取长度
        void Print();//打印链表
        void Destroy();//清空链表
        void TailCreate();//尾插法
        //bool TailInsert(T data);//尾插元素
        bool Insert(int pos, T data);//
        bool Delete(int pos, T &ret);//用ret返回删除的数据
        Node<T> *GetNode(int pos); //获取某个位置上的节点指针
    private:
        Node<T> *head_;
        Node<T> *tail_;
        int size_;
};

template <class T>
inline List<T>::List()
    :head_(NULL),
     tail_(NULL),
     size_(0)
{}

template <class T>
inline List<T>::~List()
{
    Destroy();
}

template <class T>
inline bool List<T>::IsEmpty()  //判断是否为空
{
    if(size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
inline int List<T>::GetLength()//获取长度
{
    return size_;
}

template <class T>
inline Node<T> *List<T>::GetNode(int pos) //获取某个位置上的节点指针
{
    if(pos < 0 || pos > size_)
    {
        ERR_EXIT("getnode");
    }
    Node<T> *pre = head_;
    for(int i = 0; i < pos; ++i)
    {
        pre = pre->next;
    }
    return pre;
}

template <class T>
inline void List<T>::Print()//打印链表
{
    Node<T> *pre = head_;
    while(pre->next != head_)
    {
        std::cout << pre->data << " ";
        pre = pre->next;
    }
    std::cout << pre->data << " ";
    std::cout << std::endl;
}

template <class T>
inline void List<T>::Destroy()//清空链表
{
    while(!IsEmpty())
    {
        Node<T> *cur = tail_->pre;
        Node<T> *p = tail_;
        cur->next = tail_->next;
        head_->pre = cur;
        tail_ = cur;
        delete p;
        --size_;
    }
}

template <class T>
inline void List<T>::TailCreate()//尾插法
{
    T data;
    while(std::cin >> data,!std::cin.fail())
    {
        Node<T> *cur = new Node<T>(data);//使用了Node的构造函数
        if(head_ == NULL) //第一个节点
        {
            head_ = tail_ = cur;
            tail_->next = head_;
            head_->pre = tail_;
            ++size_;
        }
        else
        {
            cur->next = head_;
            head_->pre = cur;
            cur->pre = tail_;
            tail_->next = cur;
            tail_ = cur;
            ++size_;
        }
    }
}
template <class T>
inline bool List<T>::Insert(int pos, T data)
{
    if(pos < 0 || pos >size_)
        return false;
    Node<T> *pre = GetNode(pos - 1);
    Node<T> *p = GetNode(pos);
    Node<T> *cur = new Node<T>(data);
    cur->next = p;
    p->pre = cur;
    cur->pre = pre;
    pre->next = cur;
    ++size_;
    return true;
}

template <class T>
inline bool List<T>::Delete(int pos, T &ret)//用ret返回删除的数据
{
    if(pos < 0 || pos > size_)
    {
        return false;
    }
    Node<T> *pre = GetNode(pos - 1);
    Node<T> *p = GetNode(pos);
    ret = p->data;
    pre->next = p->next;
    p->next->pre = pre;
    delete p;
    --size_;
    return true; 
}

#endif
