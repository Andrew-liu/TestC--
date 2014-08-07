#include "thread.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void queue_init(Queue *Q)
{
    Q->head_ = NULL;
    Q->tail_ = NULL;
    Q->size_ = 0;
}

void queue_destroy(Queue *Q)
{
    queue_clear(Q);
}

void queue_push(Queue *Q, task_t tsk)
{
    pNode pre = (pNode)malloc(sizeof(Node));
    pre->data = tsk;
    pre->next = NULL;
    if(is_empty(Q))
    {
        Q->head_ = Q->tail_ = pre;
    }
    else
    {
        Q->tail_->next = pre;
        Q->tail_ = pre;
    }
    ++Q->size_;
}

void queue_pop(Queue *Q)
{
    assert(!is_empty(Q));
    pNode cur = Q->head_;
    Q->head_ = Q->head_->next;
    free(cur);
    --Q->size_;
}

task_t queue_top(Queue *Q)
{
    assert(!is_empty(Q));
    return Q->head_->data;
}

void queue_clear(Queue *Q)
{
    if(!is_empty(Q))
    {
        queue_pop(Q);
    }
}

BOOL is_empty(Queue *Q)
{
    if(Q->head_ == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

size_t get_size(Queue *Q)
{
    return Q->size_;
}
