#include "server.h"


int main()
{
    Server server(IPADDRESS, PORT);
    server.Run();
}
