#include "server.h"


Server::Server(const char* ip, int port)
{
    this->listen_fd = socket_bind();
    this->epoll_fd = CreateEpoll();

    AddEvent(this->epoll_fd, this->listen_fd, EPOLLIN);
}

Server::~Server(){}

void Server::Run()
{
    while(true)
    {
        int ret = EpollWait(this->epoll_fd, this->events);
        this->HandleEvent(ret); 
    }
}

void Server::HandleEvent(int ret)
{
    for (size_t i = 0; i < ret; i++) {
        int fd = this->events[i].data.fd;

        if ((fd == this->listen_fd) && (events[i].events & EPOLLIN))
            this->HandleAccept();
        else if (this->events[i].events & EPOLLIN)
            this->HandleRead(i);
    }
}

void Server::HandleAccept()
{
    int new_client_fd = accept(this->listen_fd, NULL, NULL);
    AddEvent(this->epoll_fd, new_client_fd, EPOLLIN);
}

void Server::HandleRead(int index)
{

}


