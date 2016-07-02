#include "../include/as_condition.h"
#include <time.h>
#include <sys/time.h>

BEGINNAMESPACEASHENVALE

ASCondition::ASCondition(pthread_condattr_t *attr, ASObject *parent)
    : ASObject(parent)
{
    pthread_cond_init(&_cond, attr);
}

ASCondition::~ASCondition()
{
    pthread_cond_destroy(&_cond);
}

int ASCondition::wait(ASMutex *mutex)
{
    if(!mutex)
        return -1;

    return pthread_cond_wait(&_cond, &mutex->_mutex);
}

int ASCondition::wait(ASMutex *mutex, long timeout)
{
    struct timeval tv;
    struct timespec ts;

    if(!mutex)
        return -1;

    if(timeout < 0)
        return wait(mutex);

    if(timeout == 0)
        return mutex->trylock();

    gettimeofday(&tv, 0);
    ts.tv_sec = tv.tv_sec + (timeout / (1000 * 1000));
    ts.tv_nsec = (tv.tv_usec * 1000) + ((timeout % (1000 * 1000)) * 1000);

    return pthread_cond_timedwait(&_cond, &mutex->_mutex, &ts);
}

int ASCondition::wakeup()
{
    return pthread_cond_signal(&_cond);
}

int ASCondition::wakeupAll()
{
    return pthread_cond_broadcast(&_cond);
}

ENDNAMESPACEASHENVALE
