#ifndef _BE_DESIGNER_MODULE_SESSION_H_
#define _BE_DESIGNER_MODULE_SESSION_H_

#include "Context.h"

#include <string>
#include <list>
#include <stack>

namespace bd{
    class Module;
    class Datafield;
    class Object;
    class Transaction;
    enum EventType;
}
namespace bd{
    class Session{
    public:
        Session();
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
        virtual bool invokeEventRule(const Datafield &datafield, EventType type);
        virtual bool invokeCheckRule(const Datafield &datafield);
    protected:
        Context *_context;
        Transaction *_transaction;
        bool _isDirectCall;
        std::string _transName;
        std::stack<Transaction*> _transStack;
    };
}

#endif