#include "ThreadPool.h"

using namespace std;

void print(int i)
{
    cout << i << endl;
}

int main(int argc, const char *argv[])
{
    ThreadPool pool(5, 4);
    pool.start();
    srand(100);
    while(1)
    {
        pool.addtask(bind(&print, rand() % 100));
        sleep(1);
    }
    pool.stop();
    return 0;
}
