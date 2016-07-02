#include "as_mutex.h"


BEGINNAMESPACEASHENVALE

class ASCondition : virtual public ASObject
{
public:
    ASCondition(pthread_condattr_t * attr = 0, ASObject *parent = 0);
    ~ASCondition();

    int wait(ASMutex *mutex);
    int wait(ASMutex *mutex, long timeout/*usec*/);
    int wakeup();
    int wakeupAll();

protected:
    pthread_cond_t _cond;
};

ENDNAMESPACEASHENVALE
