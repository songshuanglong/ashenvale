#include "as_object.h"

BEGINNAMESPACEASHENVALE

class ASSocket : virtual public ASObject
{
public:
    ASSocket(ASObject *parent = 0);
    ~ASSocket();

    virtual int create() = 0;
    void close();

    static int setNonblock(int fd);
    static int setAddrReuse(int fd);
    static int setPortReuse(int fd);

protected:
    int _fd_socket;
};

ENDNAMESPACEASHENVALE
