#include "../include/as_thread.h"

BEGINNAMESPACEASHENVALE

ASThread::ASThread(ASObject *parent)
    : ASObject(parent)
{

}

ASThread::~ASThread()
{

}

int ASThread::start()
{
    return pthread_create(&_tid, 0, ASThread::routine, this);
}

int ASThread::terminate()
{
    return pthread_cancel(_tid);
}

int ASThread::join()
{
    return pthread_join(_tid, 0);
}

void *ASThread::routine(void *arg)
{
    ASThread *_this = (ASThread *)arg;

    _this->run();

    return 0;
}

ENDNAMESPACEASHENVALE
