#include "../include/as_tcpsocket.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

BEGINNAMESPACEASHENVALE

ASTcpSocket::ASTcpSocket(ASObject *parent)
    : ASSocket(parent)
{

}

ASTcpSocket::~ASTcpSocket()
{

}

int ASTcpSocket::create()
{
    if(_fd_socket >= 0){
        return -1;
    }

    _fd_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(_fd_socket < 0){
        return -1;
    }

    return 0;
}

int ASTcpSocket::bind(const std::__cxx11::string &ipAddr, unsigned short port)
{
    struct sockaddr_in addr;
    socklen_t len;

    len = sizeof(struct sockaddr_in);
    memset(&addr, 0, len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ipAddr.empty() ? inet_addr("127.0.0.1") : inet_addr(ipAddr.c_str());
    addr.sin_port = htons(port);

    return ::bind(_fd_socket, (struct sockaddr *)&addr, len);
}

ENDNAMESPACEASHENVALE
