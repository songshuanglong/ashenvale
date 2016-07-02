#include "../include/as_poll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>


BEGINNAMESPACEASHENVALE

ASPoll::ASPoll(ASObject *parent)
    : ASObject(parent)
    , _fd_epoll(-1)
    , _poll(0)
    , _poll_count(0)
{

}

ASPoll::~ASPoll()
{
    close();
}

int ASPoll::create(int fd_count)
{
    return epoll_create(fd_count);
}

int ASPoll::addEvent(IASPollEvent *ev)
{
    return eventControl(EPOLL_CTL_ADD, ev);
}

int ASPoll::modifyEvent(IASPollEvent *ev)
{
    return eventControl(EPOLL_CTL_MOD, ev);
}

int ASPoll::deleteEvent(IASPollEvent *ev)
{
    return eventControl(EPOLL_CTL_DEL, ev);
}

int ASPoll::wait(IASPollEvent **evs, int count, int timeout)
{
    int ret = 0;

    if(!evs)
        return -1;

    if(_fd_epoll < 0)
        return -1;

    if(_poll_count < count){
        _poll_count = count;
        if(_poll){
            _poll = realloc(_poll, sizeof(struct epoll_event) * _poll_count);
            if(!_poll){
                return -1;
            }
            memset(_poll, 0, sizeof(struct epoll_event) * _poll_count);
        }else{
            _poll = malloc(sizeof(struct epoll_event) * _poll_count);
            if(!_poll){
                return -1;
            }
            memset(_poll, 0, sizeof(struct epoll_event) * _poll_count);
        }
    }

    ret = epoll_wait(_fd_epoll, (struct epoll_event *)_poll, count, timeout);
    if(ret <= 0){
        return ret;
    }

    for(int i = 0; i < count; ++i)
    {
        struct epoll_event * ev = (struct epoll_event *)_poll;
        evs[i] = (IASPollEvent *)(((struct epoll_event *)ev) + i)->data.ptr;
        evs[i]->setEvents((((struct epoll_event *)ev) + i)->events);
    }

    return ret;
}

void ASPoll::close()
{
    ::close(_fd_epoll);
    _fd_epoll = -1;
}

int ASPoll::eventControl(int op, IASPollEvent *ev)
{
    struct epoll_event event;

    event.data.ptr = ev;
    event.events = ev->getEvents();
    return epoll_ctl(_fd_epoll, op, ev->getFileDescriptor(), &event);
}

ENDNAMESPACEASHENVALE
