#ifndef _PTHREAD_
#define _PTHREAD_

#include <pthread.h>

class Buffer;

class Pthread
{
    public:
        Pthread(Buffer &buffer);
        void start();
        static void *threadFunc(void *arg);
        virtual void run()
        {}
        void join();
    protected:
        pthread_t tid_;
        Buffer &buffer_;
};

class Consume : public Pthread
{
    public:
        Consume(Buffer &buffer);
        void run();

};
class Product : public Pthread
{
    public:
        Product(Buffer &buffer);
        void run();
};

#endif
