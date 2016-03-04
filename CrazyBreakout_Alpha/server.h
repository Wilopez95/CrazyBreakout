#ifndef SERVER_H
#define SERVER_H


#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

struct arguments{
    dataSocket data;
    void* Server;
};

class server
{
public:
    server();
    void run();
    virtual ~server();

    int parcerAngulo(string pMensaje);
    int parcerFuerza(string pMensaje);
    bool getIsconnect() const;

private:
    int _fd;
    sockaddr_in _socketInformation;
    bool createSocket();

    bool setKernel();
    static void* SocketThread(void *obj);
    arguments args;

    static int _angle, _power;
    static server* _Server;

    bool isconnect;
   //void setIsconnect(bool value);
};

#endif // SERVER_H
