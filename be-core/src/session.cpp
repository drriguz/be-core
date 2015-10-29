#include "bd/session.h"
#include "bd/register.h"
#include "bd/datafield.h"
#include "bd/transaction.h"
#include "bd/utils.h"
#include "bd/event.h"
#include <boost\any.hpp>


using namespace bd;

Session::Session(Context *contex):_isDirectCall(true),_context(contex){   
}

Session::~Session(){
    if (this->_transaction)
        delete this->_transaction;
	std::map<std::string, Module*>::iterator it;
	for (it = this->_staticModules.begin(); it != this->_staticModules.end(); it++) {
		Module* m = it->second;
		if (m)
			delete m;
	}
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
    bool result = Register::createTransaction(trans, t, *this->_context);
    if (!result)
        return false;
    if (this->_transaction)
        delete this->_transaction;
    this->_transaction = t;
    this->_transName = trans;
    this->_isDirectCall = !returnCall;
	this->_transaction->addChild();
	this->_transaction->bindRules(this->_context);
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

bool Session::invokeEventRule(Datafield &datafield, Event type){
	return datafield.invokeEventRules(*this->_context, type);
}

bool Session::invokeCheckRule(const Datafield &datafield){
    return false;
}

bool Session::invokeInitRule(){
    return RuleUtils::invokeInitRule(this->_transaction, *this->_context);
}

Module* Session::getStaticModule(const std::string &name) {
	return this->_staticModules[name];
}

void Session::setStaticModule(const std::string &name, Module* module) {
	Module *old = this->_staticModules[name];
	if (old){
		delete old;
		old = NULL;
	}
	this->_staticModules[name] = module;
}