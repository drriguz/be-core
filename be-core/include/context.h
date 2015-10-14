#ifndef _BE_DESIGNER_CONTEXT_H_
#define _BE_DESIGNER_CONTEXT_H_

#include <string>

namespace bd{
    class Module;
    class Auth;
    class ModuleSupport;
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
        virtual ModuleSupport* getModuleSupport();
    protected:
        Auth *_auth;
        Module *_rootModule;
        ModuleSupport *_moduleSupport;
        int _errorCode;
        std::string _sessionId;
        std::string _entityName;
        
    };
}

#endif