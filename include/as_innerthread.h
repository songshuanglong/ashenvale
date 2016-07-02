#include "as_thread.h"

BEGINNAMESPACEASHENVALE

class IASInnerThreadCallback;

class ASInnerThread : public ASThread
{
public:
    ASInnerThread(IASInnerThreadCallback *cb, ASObject *parent = 0);
    ~ASInnerThread();

protected:
    void run();

protected:
    IASInnerThreadCallback *_cb;
};

class IASInnerThreadCallback : virtual public ASObject
{
public:
    IASInnerThreadCallback(ASObject *parent = 0);
    ~IASInnerThreadCallback();

    virtual void invoke() = 0;
};

ENDNAMESPACEASHENVALE
