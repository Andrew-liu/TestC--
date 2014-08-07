#include "Queue.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    Queue<int> Q;
    int ret;
    srand(time(NULL));
    Q.push(rand()%100);
    Q.push(rand()%100);
    Q.push(rand()%100);
    Q.push(rand()%100);
    Q.push(rand()%100);
    ret = Q.top();
    cout << "ret=" << ret << endl;
    return 0;
}
