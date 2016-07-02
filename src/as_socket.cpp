#include "../include/as_socket.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>

BEGINNAMESPACEASHENVALE

ASSocket::ASSocket(ASObject *parent)
    : ASObject(parent)
    , _fd_socket(-1)
{

}

ASSocket::~ASSocket()
{
    close();
}

void ASSocket::close()
{
    ::close(_fd_socket);
    _fd_socket = -1;
}

int ASSocket::setNonblock(int fd)
{
    int flags = 0;

    flags = fcntl(fd, F_GETFL);
    if(flags < 0){
        return -1;
    }

    if(flags & O_NONBLOCK)
        return 0;

    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int ASSocket::setAddrReuse(int fd)
{
    int opval = 1;

    return setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opval, sizeof(int));
}

int ASSocket::setPortReuse(int fd)
{
    int opval = 1;

    return setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &opval, sizeof(int));
}

ENDNAMESPACEASHENVALE
