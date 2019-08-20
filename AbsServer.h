#ifndef __AbsServer__
#define __AbsServer__
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


using namespace std;

class Server
{
public:
    Server();
    ~Server();
    virtual Bind(){};
    virtual Listen(){};
    virtual Run(){};
}


#endif __AbsServer__
