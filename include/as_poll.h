#include "as_object.h"
#include "as_pollevent.h"

BEGINNAMESPACEASHENVALE

class ASPoll : virtual public ASObject
{
public:
    ASPoll(ASObject *parent = 0);
    ~ASPoll();

    int create(int fd_count);
    int addEvent(IASPollEvent *ev);
    int modifyEvent(IASPollEvent *ev);
    int deleteEvent(IASPollEvent *ev);
    int wait(IASPollEvent **evs, int count, int timeout);
    void close();

protected:
    int eventControl(int op, IASPollEvent *ev);

protected:
    int _fd_epoll;
    void * _poll;
    int _poll_count;
};

ENDNAMESPACEASHENVALE
