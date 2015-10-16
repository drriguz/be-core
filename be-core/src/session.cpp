#include "session.h"
#include "register.h"
#include "transaction.h"
#include "utils.h"
#include <boost\any.hpp>


using namespace bd;

Session::Session():_isDirectCall(true){
    this->_context = new Context();
}

Session::~Session(){
    if (this->_transaction)
        delete this->_transaction;
    if (this->_context)
        delete this->_context;
}

bool Session::isDirectCall(){
    return this->_isDirectCall;
}

bool Session::isReturnCall(){
    return !this->_isDirectCall;
}

bool Session::isHomeTrans(){
    return _transName == std::string("office");
}

std::stack<Transaction*> Session::getTransactionStack(){
    return this->_transStack;
}

bool Session::chain(const std::string &trans, bool returnCall){
    Transaction *t = NULL;
    bool result = Register::createTransaction(trans, t);
    if (!result)
        return false;
    if (this->_transaction)
        delete this->_transaction;
    this->_transaction = t;
    this->_transName = trans;
    this->_isDirectCall = !returnCall;
    this->invokeInitRule();
    return true;
}

Transaction*  Session::getTransaction(){
    return this->_transaction;
}

bool Session::checkAll(const Module &module){
    return true;
}

bool Session::checkAll(const Datafield &datafield){
    return true;
}

Object* Session::getObject(const std::string &url){    
    std::vector<std::string> paths;
    UrlUtils::getSubPath(url, paths);
    std::vector<std::string>::iterator it;
    Object *m = (Object*)this->_transaction;
    for (it = paths.begin(); it != paths.end(); it++){
        std::string p = *it;
        if (!m)
            break;
        
        if (m->getType() == ObjectType::DATAFIELD)
            return m;
        if (m->getType() == ObjectType::MODULE)
            m = ((Module*)m)->getObject(p);
    }
    if (m)
        return m;
    return NULL;
}

bool Session::setValue(const std::string &url, const std::string& value){
    std::string tmp(url);

    return false;
}

bool Session::setValue(const std::string &url, int value){
    return false;
}

bool Session::invokeEventRule(const Datafield &datafield, EventType type){
    return false;
}

bool Session::invokeCheckRule(const Datafield &datafield){
    return false;
}

bool Session::invokeInitRule(){
    return RuleUtils::invokeInitRule(this->_transaction, *this->_context);
}