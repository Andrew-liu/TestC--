#include "Queue.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    Queue<int> Q;
    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    Q.Push(4);
    Q.Push(5);
    Q.Push(6);
    Q.Debug();
    cout << Q.Top() << endl;
    cout << Q.Size() <<endl;
    return 0;
}
