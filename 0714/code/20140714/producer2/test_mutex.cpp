#include "MutexLock.h"
#include <iostream>

using namespace std;
int main(int argc, const char *argv[])
{
    MutexLock lock;

    lock.lock();
    cout << "lock " << endl;
    lock.lock();
    cout << "lock2 " << endl;
    return 0;
}
