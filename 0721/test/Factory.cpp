#include "Factory.h"

using namespace std;

Factory::Factory(size_t bufferSize,
                 size_t prodecerNum,
                 size_t consumerNum)
    :bufferSize_(bufferSize),
     buffer_(bufferSize_),
     prodecerNum_(prodecerNum),
     consumerNum_(consumerNum),
     produceThreads_(prodecerNum_, ProduceThread(buffer_)),
     consumeThreads_(consumerNum_, ConsumeThread(buffer_))
{
}

void Factory::start()
{
    for(vector<ProduceThread>::iterator it = produceThreads_.begin(); it != produceThreads_.end(); ++it){
        it->start();
    }


    for(vector<ConsumeThread>::iterator it = consumeThreads_.begin(); it != consumeThreads_.end(); ++it){
        it->start();
    }

    for(vector<ProduceThread>::iterator it = produceThreads_.begin(); it != produceThreads_.end(); ++it){
        it->join();
    }

    for(vector<ConsumeThread>::iterator it = consumeThreads_.begin(); it != consumeThreads_.end(); ++it){
        it->join();
    }
}
