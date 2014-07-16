#include "Queue.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    Queue Q;
    srand(123);
    Q.push(rand() % 100);
    Q.push(rand() % 100);
    Q.push(rand() % 100);
    Q.push(rand() % 100);

    assert(Q.getSize());
    assert(!Q.isEmpty());
    
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();

    assert(Q.isEmpty() == true);

    return 0;
}
