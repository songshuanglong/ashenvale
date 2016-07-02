#include "as_socket.h"
#include <string>

BEGINNAMESPACEASHENVALE

class ASTcpSocket : public ASSocket
{
public:
    ASTcpSocket(ASObject *parent = 0);
    ~ASTcpSocket();

    virtual int create();
    virtual int bind(const std::string &ipAddr, unsigned short port);
};

ENDNAMESPACEASHENVALE
