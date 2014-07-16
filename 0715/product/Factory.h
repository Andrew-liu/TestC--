#ifndef _FACTORY_
#define _FACTORY_

#include <vector>
#include "Buffer.h"
#include "ProduceThread.h"
#include "ConsumeThread.h"

class Factory
{
    public:
        Factory(size_t buf_size,
                size_t pro_size,
                size_t con_size);
        void start();

    private:
        size_t bufsize_;
        Buffer buffer_;
        size_t prosize_;
        size_t consize_;
        std::vector<ProduceThread> produce_;
        std::vector<ConsumeThread> consume_;
};


#endif
