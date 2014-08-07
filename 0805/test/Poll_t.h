#ifndef _POLL_T_
#define _POLL_T_
#include "Sever.h"
#include <functional>
#include <poll.h>

class Poll_t : public Sever
{
    public:
        Poll_t();
        ~Poll_t();
        void wait();
        void handle_accept();
        void handle_data();
        void setcallback(const HandleCallback &callback);
    private:
        void add_fd(int peerfd);
        void del_fd(int i);
        struct pollfd client_[2048];
        int maxi_;
        int readn_;
};

#endif
