#include "Pthread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Pthread::Pthread(Buffer &buffer)
    :tid_(0), 
    buffer_(buffer)
{}

void Pthread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void *Pthread::threadFunc(void *arg)
{
    Pthread *pt = static_cast<Pthread *>(arg); //在分别定义两个子类对象时,传入子类的this,父类指针指向一个子类,本质对象是子类
    pt->run();//然后由于virtual run(),根据对象调用,动态绑定,所以确定使用子类的run
    return NULL;
}

void Pthread::join()
{
    pthread_join(tid_,NULL);
}


Consume::Consume(Buffer &buffer)
    :Pthread(buffer)
{}

Product::Product(Buffer &buffer)
    :Pthread(buffer)
{}


void Consume::run()
{
    while(1)
    {
        int data = buffer_.consume();
        cout << "consume a data" <<data << endl;
        sleep(1);
    }
}
void Product::run()
{
    while(1)
    {
        int data = rand()%1000;
        cout << "produce a data:" << data << endl;
        buffer_.produce(data);
        sleep(5);
    }
    
}

int main(int argc, const char *argv[])
{
    Buffer buffer(5);
    Product p1(buffer);
    Consume c1(buffer);
    Pthread &x1 = p1;
    Pthread &x2 = c1;
    x1.start();
    x2.start();
    x1.join();
    x2.join();
  /*
    Pthread *pth1 = new Product(buffer);
    Pthread *pth2 = new Consume(buffer);
 
    pth1->start();
    pth2->start();

    pth1->join();
    pth2->join();
*/
    /*
    Product p1(buffer);
    Consume c1(buffer);
    p1.start();
    c1.start();

    p1.join();
    c1.join();
    */
    return 1;
}
