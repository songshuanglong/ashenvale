#include "../include/as_innerthread.h"

BEGINNAMESPACEASHENVALE

ASInnerThread::ASInnerThread(IASInnerThreadCallback *cb, ASObject *parent)
    : ASThread(parent)
    , _cb(cb)
{

}

ASInnerThread::~ASInnerThread()
{

}

void ASInnerThread::run()
{
    if(_cb)
        _cb->invoke();
}

IASInnerThreadCallback::IASInnerThreadCallback(ASObject *parent)
    : ASObject(parent)
{

}

IASInnerThreadCallback::~IASInnerThreadCallback()
{

}

ENDNAMESPACEASHENVALE
