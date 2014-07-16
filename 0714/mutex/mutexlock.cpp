#include "mutexlock.h"
using namespace std;
Query::Query()
{
    head_ = NULL;
    tail_ = NULL;
    cnt_  = 0;
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&empty_, NULL);
    pthread_cond_init(&full_, NULL);
}
Query::~Query()
{
    clear_query();
    pthread_mutex_destroy(&mutex_);
    pthread_cond_destroy(&empty_);
    pthread_cond_destroy(&full_);
}

void Query::lock()
{
    pthread_mutex_lock(&mutex_);
}
void Query::unlock()
{
    pthread_mutex_unlock(&mutex_);
}


void Query::wait_empty()
{
    pthread_cond_wait(&empty_, &mutex_);
}
void Query::wait_full()
{
    pthread_cond_wait(&full_, &mutex_);
}
void Query::signal_empty()
{
    pthread_cond_signal(&empty_);
}
void Query::signal_full()
{
    pthread_cond_signal(&full_);
}


void Query::push_query(int data)
{
    Node *pre = new Node;//C++式分配内存空间
    pre->data = data;
    pre->next = NULL;//初始化
    if(this->empty_query())
    {
            head_ = tail_ = pre;
           
        }
    else
    {
            tail_->next = pre;
            tail_ = pre;
        }
    ++cnt_;//++(this->cnt);
}
void Query::pop_query()
{
    if(!empty_query())
    {
            Node *pre=head_;
            head_=head_->next;
            --cnt_;
            delete pre;//C++式释放内存
        }
    else
    {
            throw runtime_error("pop error!");
        }
}
int Query::top_query()
{
    if(!empty_query())
    {
            return head_->data;
        }
    else
    {
            throw runtime_error("top error!");
        }
}
bool Query::empty_query()//判断是否为空
{
    if(head_==NULL)
    {
            return true;
        }
    else
        return false;
}

int  Query::size_query()
{
    return cnt_;
}
void Query::clear_query()
{
    while(!empty_query())
    {
        pop_query();
    }
}



Pthread::~Pthread()
{}
void Pthread::create_producer(Query *queue)
{
    cout << "pro " << endl;
    cout << "cnt " << queue->cnt_ << endl;
    cout << "data" <<queue->head_ << endl;
    pthread_create(&tid_, NULL, &Pthread::producer, (void *)queue);
}

void Pthread::create_consumer(Query *queue)
{
    cout << "con "<< endl;
    pthread_create(&tid_, NULL,&Pthread::consumer, queue);
}
void Pthread::join()
{
    pthread_join(tid_, NULL);
}
void Pthread::detach()
{
    pthread_detach(tid_);
}

void *(Pthread::*producer)(void *arg)
{
    cout << "ok " << endl;
//    Query *queue = (Query *)arg;
    Query *queue = static_cast<Query *>(arg);
    cout << "cnt " << queue->cnt_ <<endl;
    while(1)
    {
        queue->lock();
        while(queue->size_query() >= BUFFERSIZE) 
        {
            queue->wait_empty();
        }
        int data = rand()%100;
        queue->push_query(data);
        cout << "producer " << data << endl;
        queue->signal_full();
        queue->unlock();
        sleep(1);
    }
    return NULL;
    
}
void *(Pthread::*consumer)(void *arg)
{
    cout << "ok" << endl;
    Query *queue=(Query *)arg;
//    Query *queue = static_cast<Query *>(arg);
    cout << "cnt " << queue->cnt_ <<endl;
    while(1)
    {
        queue->lock();
        while(queue->empty_query())
        {
            queue->wait_full();
        }
        int data = queue->top_query();
        queue->pop_query();
        cout << "consumer " << data << endl;
        queue->signal_empty();
        queue->unlock();
    }
    return NULL;
}
int main(int argc, const char *argv[])
{
    Pthread producer,consumer;
    Query queue;
    producer.create_producer(&queue);
    consumer.create_consumer(&queue);
    return 0;
}             
