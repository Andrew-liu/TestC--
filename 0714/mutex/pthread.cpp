#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
using namespace std;
class Pthread
{
    public:
        Pthread();
        ~Pthread();
        void create();
        void join();
        void detach();
        static void *producer(void *arg);
        //static void *consumer(void *arg);
    private:
        pthread_t tid_;
        int       a_;
};
Pthread::Pthread():tid_(-1),a_(0)
{}
Pthread::~Pthread()
{}
void Pthread::create()
{
    pthread_create(&tid_, NULL, producer, this);
}
void Pthread::join()
{
    pthread_join(tid_, NULL);
}
void Pthread::detach()
{
    pthread_detach(tid_);
}
void *Pthread::producer(void *arg)
{
    Pthread *pt = static_cast<Pthread *>(arg);
    while(1)
    {
        ++pt->a_;
        cout << "comsumer " << pt->a_ << endl;
    }
    return NULL;
}
int main(int argc, const char *argv[])
{
    Pthread thread;
    thread.create();
    thread.join();
    return 0;
}
