#include "bd/context.h"
#include "bd/auth.h"
#include "bd/persistence.h"
#include "bd/module.h"
#include "bd/session.h"
#include "bd/presentation.h"
#include "bd/extApi.h"

using namespace bd;

Context::Context(){
	this->_session = new Session(this);
	this->_auth = new Auth();
	this->_presentation = new Presentation();
	this->_persistence = new Persistence();
}

Context::~Context(){
	if (this->_session)
		delete this->_session;
	if (this->_auth)
		delete this->_auth;
	if (this->_presentation)
		delete this->_presentation;
	if (this->_persistence)
		delete this->_persistence;
	if (this->_uiSupport)
		delete this->_uiSupport;
}

Auth* Context::getAuth(){
    return this->_auth;
}

int Context::getErrorCode(){
    return this->_errorCode;
}

bool Context::login(const std::string& user, const std::string& passwd) {
	if (!this->_auth)
		return false;
	return this->_auth->login(user, passwd);
}
bool Context::logout(){
	if (!this->_auth)
		return false;
	return this->_auth->logout();
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
    return this->_persistence;
}

Presentation* Context::getPresentation() {
	return this->_presentation;
}
void Context::setPersistence(Persistence *Persistence){
    this->_persistence = Persistence;
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

void Context::setUiSupport(UiSupport* ui) {
	this->_uiSupport = ui;
}
UiSupport* Context::getUiSupport() {
	return this->_uiSupport;
}