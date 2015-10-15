#include "Context.h"
#include "Auth.h"
#include "Persistence.h"
#include "module.h"
using namespace bd;

Context::Context(){

}

Context::~Context(){

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
    return this->_rootModule;
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