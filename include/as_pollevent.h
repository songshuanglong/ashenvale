#include "as_object.h"

BEGINNAMESPACEASHENVALE

class IASPollEvent : virtual public ASObject
{
public:
    IASPollEvent(ASObject *parent = 0);
    ~IASPollEvent();

    unsigned int getEvents();
    void setEvents(unsigned int events);
    virtual void onEvents() = 0;
    virtual int getFileDescriptor() = 0;

protected:
    unsigned int _events;
};

ENDNAMESPACEASHENVALE
