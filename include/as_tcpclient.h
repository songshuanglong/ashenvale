#include "as_tcpsocket.h"


BEGINNAMESPACEASHENVALE

class ASTcpClient : public ASTcpSocket
{
public:
    ASTcpClient(ASObject *parent = 0);
    ~ASTcpClient();

    virtual int connect(std::string &ipAddr, unsigned short port);
    virtual int send(const void *buf, size_t len, int flags);
    virtual int recv(void *buf, size_t len, int flags);
};

ENDNAMESPACEASHENVALE
