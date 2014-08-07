#include "Thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;

//继承必须使用头文件
class HelloThread : public Thread
{
    public:
        HelloThread()
            :count_(1)
        {}
        void run()
        {
            while(1){
                sleep(1);
                cout << "Hello "  << count_++ << endl;
            }
        }
    private:
        int count_;
};


int main(int argc, const char *argv[])
{
    HelloThread t;
    t.start();

    t.join();
    return 0;
}


