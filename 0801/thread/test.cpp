#include "Thread.h"

using namespace std;

void *handler(void *arg)
{
    cout << "success" << endl;
}

int main(int argc, const char *argv[])
{
    Thread T(handler);
    T.create();
    T.join();
    return 0;
}
