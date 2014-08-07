#include "Queue.hpp"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char *argv[])
{
    Queue<string> Q;

    Q.push("beijing");
    Q.push("shanghai");
    Q.push("nanjing");

    while(!Q.isEmpty())
    {
        cout << Q.top() << endl;
        Q.pop();
    }

    return 0;
}
