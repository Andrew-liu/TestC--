#ifndef ANDREW
#define ANDREW

#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdexcept>
#include <time.h>
#include <cstdlib>

#define BUFFERSIZE 5

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
class Query
{
   friend class Pthread;
    private:
        struct Node *head_;//头部出队
        struct Node *tail_;//尾部入队
        int cnt_;  //方便计算长度
        pthread_mutex_t mutex_;
        pthread_cond_t full_;
        pthread_cond_t empty_;
    public:
        Query();
        ~Query();
        //调用自身不用再传参,含有this指针
        void push_query(int data);//入队
        void pop_query();//出队
        int  top_query();//输出队头元素
        bool empty_query();//判断是否为空
        int  size_query();//判断队列大小
        void clear_query();

        void lock();
        void unlock();
        void wait_empty();
        void wait_full();
        void signal_empty();
        void signal_full();
};
class Pthread
{
    public:
//        Pthread(Query *queue);
        ~Pthread();
        void create_producer(Query *queue);
        void create_consumer(Query *queue);
        void join();
        void detach();
        static void *(*producer)(void *arg);
        static void *(*consumer)(void *arg);
    private:

        pthread_t tid_;
    //    int       a_; 
};
#endif
