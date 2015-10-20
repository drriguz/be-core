#ifndef _BE_DESIGNER_CONTEXT_H_
#define _BE_DESIGNER_CONTEXT_H_

#include <string>

namespace bd{
    class Module;
    class Auth;
	class Presentation;
    class Persistence;
	class Session;
}

namespace bd{
    class Context{
    public:
        Context();
        ~Context();
    public:
        virtual Auth* getAuth();
        virtual int getErrorCode();
		virtual bool login(const std::string& user, const std::string& passwd);
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
		virtual Session* getSession();
		virtual Presentation* getPresentation();
    protected:
		Session* _session;
        Auth *_auth;
        Persistence *_persistence;
		Presentation *_presentation;
        int _errorCode;
        std::string _sessionId;
        std::string _entityName;
        
    };
}

#endif