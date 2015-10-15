#ifndef _BE_DESIGNER_CONTEXT_H_
#define _BE_DESIGNER_CONTEXT_H_

#include <string>

namespace bd{
    class Module;
    class Auth;
    class Persistence;
}

namespace bd{
    class Context{
    public:
        Context();
        ~Context();
    public:
        virtual Auth* getAuth() const;
        virtual int getErrorCode();
        virtual bool logout();
        virtual std::string getSessionId() const;
        virtual std::string getEntity() const;
        virtual Module* getRootModule();
        virtual Persistence* getPersistence();
        virtual void setPersistence(Persistence *Persistence);
        virtual void setAuth(Auth *auth);
        virtual void setSessionId(const std::string &sessionId);
        virtual void setEntity(const std::string &entityName);
        virtual void setErrorCode(int errorCode);
    protected:
        Auth *_auth;
        Module *_rootModule;
        Persistence *_Persistence;
        int _errorCode;
        std::string _sessionId;
        std::string _entityName;
        
    };
}

#endif