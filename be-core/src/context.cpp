#include "context.h"
#include "auth.h"
#include "persistence.h"
#include "module.h"
#include "session.h"
using namespace bd;

Context::Context(){
	this->_session = new Session(*this);
}

Context::~Context(){
	if (this->_session)
		delete this->_session;
}

Auth* Context::getAuth() const{
    return this->_auth;
}

int Context::getErrorCode(){
    return this->_errorCode;
}

bool Context::logout(){
    return true;
}

std::string Context::getSessionId() const{
    return this->_sessionId;
}

std::string Context::getEntity() const{
    return this->_entityName;
}

Module* Context::getRootModule(){
    return (Module*)this->_session->getTransaction();
}
Session* Context::getSession() {
	return this->_session;
}
Persistence* Context::getPersistence(){
    return this->_Persistence;
}

void Context::setPersistence(Persistence *Persistence){
    this->_Persistence = Persistence;
}

void Context::setAuth(Auth *auth){
    this->_auth = auth;
}

void Context::setSessionId(const std::string &sessionId){
    this->_sessionId = sessionId;
}

void Context::setEntity(const std::string &entityName){
    this->_entityName = entityName;
}

void Context::setErrorCode(int errorCode){
    this->_errorCode = errorCode;
}