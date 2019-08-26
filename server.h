#ifndef __Server__
#define __Server__
#include "stdafx.h"
#include "epoll.h"

class Server
{
public:
    Server(const char* ip, int port);
    ~Server();
    void Run();
    void HandleEvent(int ret);
    void HandleAccept();
    void HandleRead(int index);

private:
    // bind socket fd
    int listen_fd;
    // epoll pool fd
    int epoll_fd;
    // client events
    epoll_event events[CLIENT_COUNT];
};


#endif 
