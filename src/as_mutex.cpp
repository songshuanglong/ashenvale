#include "../include/as_mutex.h"

BEGINNAMESPACEASHENVALE

ASMutex::ASMutex(pthread_mutexattr_t *attr, ASObject *parent)
    : ASObject(parent)
{
    pthread_mutex_init(&_mutex, attr);
}

ASMutex::~ASMutex()
{
    pthread_mutex_destroy(&_mutex);
}

int ASMutex::lock()
{
    return pthread_mutex_lock(&_mutex);
}

int ASMutex::trylock()
{
    return pthread_mutex_trylock(&_mutex);
}

int ASMutex::unlock()
{
    return pthread_mutex_unlock(&_mutex);
}

ENDNAMESPACEASHENVALE
