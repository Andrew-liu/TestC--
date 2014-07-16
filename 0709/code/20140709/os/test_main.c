#include "queue.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, const char *argv[])
{
    Queue Q;
    queue_init(&Q);
    queue_push(&Q, 3);
    queue_push(&Q, 5);

    assert(!queue_is_empty(&Q));
    assert(queue_get_size(&Q) == 2);

    int t = queue_top(&Q);
    printf("%d\n", t);
    queue_pop(&Q);
    t = queue_top(&Q);
    printf("%d\n", t);
    queue_pop(&Q);

    assert(queue_is_empty(&Q));

    return 0;
}
