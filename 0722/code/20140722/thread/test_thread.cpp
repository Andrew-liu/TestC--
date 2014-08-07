#include "Thread.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class TestThread : public Thread
{
    public:
        void run()
        {
            while(1)
            {
                sleep(1);
                cout << "Hello ... " << endl;
            }
        }
};

int main(int argc, const char *argv[])
{
    TestThread t;
    t.start();
    t.join();
    return 0;
}
