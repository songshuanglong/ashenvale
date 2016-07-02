#include "as_object.h"
#include <pthread.h>

BEGINNAMESPACEASHENVALE

class ASThread : virtual public ASObject
{
public:
    ASThread(ASObject *parent = 0);
    ~ASThread();

    int start();
    int terminate();
    int join();

protected:
    static void *routine(void *arg);
    virtual void run() = 0;

protected:
    pthread_t _tid;
};

ENDNAMESPACEASHENVALE
