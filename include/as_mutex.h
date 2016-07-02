#include "as_object.h"
#include <pthread.h>

BEGINNAMESPACEASHENVALE

class ASMutex : virtual public ASObject
{
    friend class ASCondition;
public:
    ASMutex(pthread_mutexattr_t *attr = 0, ASObject *parent = 0);
    ~ASMutex();

    int lock();
    int trylock();
    int unlock();

protected:
    pthread_mutex_t _mutex;
};

ENDNAMESPACEASHENVALE
