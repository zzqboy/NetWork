#ifndef __epoll__
#define __epoll__

#include "stdafx.h"
#include <sys/epoll.h>


inline int CreateEpoll(int size=EPOLL_SIZE)
{
    return epoll_create(size);
}

inline void AddEvent(int epoll_fd, int add_fd, int event)
{
    epoll_event ev;
    ev.events = event;
    ev.data.fd = add_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, add_fd, &ev);
}

inline int EpollWait(int epoll_fd, struct epoll_event* events, int epoll_size=EPOLL_SIZE)
{
    return epoll_wait(epoll_fd, events, epoll_size, -1);
}

inline void DeleteEvent(int epoll_fd, int client_fd, int event)
{
    epoll_event ev;
    ev.events = event;
    ev.data.fd = client_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &ev);
}

#endif
