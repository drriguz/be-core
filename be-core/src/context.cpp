#include "Context.h"
#include "Auth.h"
#include "ModuleSupport.h"
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

ModuleSupport* Context::getModuleSupport(){
    return this->_moduleSupport;
}
