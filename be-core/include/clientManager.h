#ifndef _BE_DESIGNER_CLIENT_MANAGER_H_
#define _BE_DESIGNER_CLIENT_MANAGER_H_

#include <map>

namespace bd{
    class ClientManager{
    public:
        ClientManager();
        ~ClientManager();
    public:
        static int getInstance();
        std::map<std::string, int> getClient(std::string clientId);
        bool addClient(std::string clientId, int ctx);
        bool removeClient(std::string clientId);
    private:
        std::map<std::string, int> _clientMap;
    };
}

#endif
