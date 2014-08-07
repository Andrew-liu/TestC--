#include "Sever.h"
#include <functional>
#include <sys/select.h>

class Select_t : public Sever
{
    public:
        typedef std::function< void (int, char *) > SelectCallback;
        Select_t(SelectCallback callback);
        ~Select_t();
        void wait();
        void handle_accept();
        void handle_data();
    private:
        void add_fd(int peerfd);
        void del_fd(int i);
        fd_set allset_;
        fd_set rset_;
        int client_[FD_SETSIZE];
        int maxi_;
        int maxfd_;
        int readn_;
        SelectCallback callback_;
};
