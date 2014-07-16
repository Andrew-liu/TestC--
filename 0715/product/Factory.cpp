#include "Factory.h"


using namespace std;


Factory::Factory(size_t buf_size,size_t pro_size,size_t con_size)
    :bufsize_(buf_size),
     buffer_(bufsize_),
     prosize_(pro_size),
     consize_(con_size),
     produce_(prosize_, ProduceThread(buffer_)),
     consume_(consize_, ConsumeThread(buffer_))
{
}

void Factory::start()
{
    for(vector<ProduceThread>::iterator it = produce_.begin(); it != produce_.end(); ++ it)
    {
        it->start();
    }
    for(vector<ConsumeThread>::iterator it = consume_.begin(); it != consume_.end(); ++ it)
    {
        it->start();
    }
    for(vector<ProduceThread>::iterator it = produce_.begin(); it != produce_.end(); ++ it)
    {
        it->join();
    }
    for(vector<ConsumeThread>::iterator it = consume_.begin(); it != consume_.end(); ++ it)
    {
        it->join();
    }
}

int main(int argc, const char *argv[])
{
   Factory first(5, 2, 1);
   first.start();
    return 0;
}
