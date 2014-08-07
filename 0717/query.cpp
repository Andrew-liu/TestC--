#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <cstdlib>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
/*
class Q_node
{
    public:
        int data;
        Q_node *next;
}
*/
class Query
{
    private:
        struct Node *head_;//头部出队
        struct Node *tail_;//尾部入队
        int cnt_;  //方便计算长度
    public:
        Query():head_(NULL),tail_(NULL),cnt_(0){}
        //复制构造函数
        Query(const Query &other):
            head_(NULL),
            tail_(NULL),
            cnt_()
        {
            for(Node *pt = other.head_; pt != NULL; pt = pt->next)
            {
                push_query(pt->data);
            }
        }

        //赋值操作符
        Query &operator = (const Query &other)
        {
            if(this != &other)
            {
                delete head_;
                delete tail_;
                head_ = new Node(*(other.head_));
                tail_ = new Node(*(other.tail_));
                cnt_  = other.cnt_;
            }
        }
        ~Query()
        {
            while(!empty_query())
            {
                pop_query();
            }
        }
        //调用自身不用再传参,含有this指针
        void push_query(int data);//入队
        void pop_query();//出队
        int  top_query();//输出队头元素
        bool empty_query();//判断是否为空
        int  size_query();//判断队列大小
        void debug_query(); 
};
//队尾入队
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

//队头出队
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
void Query::debug_query()
{
    Node *pre=head_;
    while(!empty_query())
    {
        cout << (head_->data) << endl;
        head_ = head_->next;
    }
}
int  Query::size_query()
{
    /*      若不定义cnt 
     *      使用while循环判断
     *
     */
    return cnt_;
}
int main(int argc, const char *argv[])
{
    Query Queue;
    int ret;
    srand(time(NULL));
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    Queue.push_query(rand()%100);
    ret = Queue.top_query();
//    Queue.debug_query();
    return 0;
}
