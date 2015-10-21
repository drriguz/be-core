#ifndef _BE_DESIGNER_MODULE_SESSION_H_
#define _BE_DESIGNER_MODULE_SESSION_H_

#include "Context.h"

#include <string>
#include <list>
#include <stack>
#include <map>

namespace bd{
    class Module;
    class Datafield;
    class Object;
    class Transaction;
    class Event;
}
namespace bd{
    class Session{
    public:
        Session(Context &contex);
        ~Session();
    public:
        virtual bool isDirectCall();
        virtual bool isReturnCall();
        virtual bool isHomeTrans();
        virtual std::stack<Transaction*> getTransactionStack();
        virtual bool chain(const std::string &trans, bool returnCall);
        virtual Transaction*  getTransaction();
        virtual bool checkAll(const Module &module);
        virtual bool checkAll(const Datafield &datafield);
        virtual Object* getObject(const std::string &url);        
        virtual bool setValue(const std::string &url, const std::string& value);
        virtual bool setValue(const std::string &url, int value);
        virtual bool invokeEventRule(Datafield &datafield, Event type);
        virtual bool invokeCheckRule(const Datafield &datafield);
        virtual bool invokeInitRule();

		virtual Module* getStaticModule(const std::string &name);
		virtual void setStaticModule(const std::string &name, Module* module);
    protected:
        Context *_context;
        Transaction *_transaction;
        bool _isDirectCall;
        std::string _transName;
        std::stack<Transaction*> _transStack;
		std::map<std::string, Module*> _staticModules;
    };
}

#endif