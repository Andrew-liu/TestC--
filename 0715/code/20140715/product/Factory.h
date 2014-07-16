#ifndef FACTORY_H_
#define FACTORY_H_ 

#include <vector>
#include "Buffer.h"
#include "ProduceThread.h"
#include "ConsumeThread.h"

class Factory
{
    public:
        
        Factory(size_t bufferSize_, 
                size_t prodecerNum_, 
                size_t consumerNum_);
        void start();

    private:
        size_t bufferSize_;
        Buffer buffer_;
        size_t prodecerNum_;
        size_t consumerNum_;
        std::vector<ProduceThread> produceThreads_;
        std::vector<ConsumeThread> consumeThreads_;
};

#endif  /*FACTORY_H_*/
