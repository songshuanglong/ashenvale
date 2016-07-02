#include "../include/as_tcpclient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

BEGINNAMESPACEASHENVALE

ASTcpClient::ASTcpClient(ASObject *parent)
    : ASTcpSocket(parent)
{

}

ASTcpClient::~ASTcpClient()
{

}

int ASTcpClient::connect(std::string &ipAddr, unsigned short port)
{
    struct sockaddr_in addr_svr;
    socklen_t addr_len;

    if(ipAddr.empty() || !port){
        return -1;
    }

    addr_len = sizeof(struct sockaddr_in);
    memset(&addr_svr, 0, addr_len);
    addr_svr.sin_family = AF_INET;
    addr_svr.sin_addr.s_addr = inet_addr(ipAddr.c_str());
    addr_svr.sin_port = htons(port);

    return ::connect(_fd_socket, (struct sockaddr *)&addr_svr, addr_len);
}

int ASTcpClient::send(const void *buf, size_t len, int flags)
{
    return ::send(_fd_socket, buf, len, flags);
}

int ASTcpClient::recv(void *buf, size_t len, int flags)
{
    return ::recv(_fd_socket, buf, len, flags);
}

ENDNAMESPACEASHENVALE
