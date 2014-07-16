#include "queue.h"
void queue_init(Queue *Q)
{
    Q->head=NULL;
    Q->tail=NULL;
    Q->size=0;
}

void queue_push(Queue *Q, int data)
{
    p_node p=(p_node)malloc(sizeof(q_node));//p_node表示队列中的一个结点
    p->data=data;
    p->next=NULL;
    if(queue_empty(Q))//队列为空
    {
        Q->head=Q->tail=p;
    }
    else//队列不为空,尾部入队,
    {
        Q->tail->next=p;//尾部指向新插入的指针
        Q->tail=p;//移动尾指针
    }
    ++(Q->size);
}
void queue_pop(Queue *Q)//要判断头部是否为空
{
    assert(!queue_empty(Q));
    p_node p=Q->head;
    Q->head=Q->head->next;
    free(p);
    Q->size --;
}

int queue_top(Queue *Q)
{
    assert(!queue_empty(Q));
    return Q->head->data;//尾进头出
}
void queue_clear(Queue *Q)
{
    while(!queue_empty(Q))
    {
        queue_pop(Q);    
    }
}
int queue_empty(Queue *Q)
{
    return Q->head==NULL; //判断队列不否为空
}
int queue_size(Queue *Q)
{
    return Q->size;
}
