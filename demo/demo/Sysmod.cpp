
#include "bd/be-designer.h"
#include "Sysmod.h"

using namespace bd;
using namespace tst;
Sysmod::Sysmod() {
	this->_user = new Datafield(typeid(std::string).name());
	this->_bch = new Datafield(typeid(std::string).name());
	this->_token = new Datafield(typeid(std::string).name());
	this->_sysmod_Init_10 = new Sysmod_Init_10(this);
}
Sysmod::Sysmod(const Sysmod& sysmod) {
	this->_user = new Datafield(*sysmod._user);
	this->_bch = new Datafield(*sysmod._bch);
	this->_token = new Datafield(*sysmod._token);
	this->_sysmod_Init_10 = new Sysmod_Init_10(this);
}
Sysmod::~Sysmod() {
	if (this->_user)
		delete this->_user;
	if (this->_bch)
		delete this->_bch;
	if (this->_token)
		delete this->_token;
	if (this->_sysmod_Init_10)
		delete this->_sysmod_Init_10;
}
void Sysmod::addChild() {
	if (!this->_childAdded) {
		this->_datafields.insert(std::make_pair(std::string("user"), this->_user));
		this->_datafields.insert(std::make_pair(std::string("bch"), this->_bch));
		this->_datafields.insert(std::make_pair(std::string("token"), this->_token));
		this->_childAdded = true;
	}
}
void Sysmod::bindRules(Context *context) {
	if (!this->_eventBinded) {
		context->getRootModule()->addInitRule(this->_sysmod_Init_10);
		this->_eventBinded = true;
	}
}

void Sysmod::set_User(const std::string & value) {
	this->_user->setValue(value);
}
void Sysmod::set_Bch(const std::string &value) {
	this->_bch->setValue(value);
}
void Sysmod::set_Token(const std::string &value) {
	this->_token->setValue(value);
}

Datafield* Sysmod::get_User() {
	return this->_user;
}
Datafield* Sysmod::get_Bch() {
	return this->_bch;
}
Datafield* Sysmod::get_Token() {
	return this->_token;
}
//
Sysmod_Init_10::Sysmod_Init_10(Sysmod *parent) :Rule((Module*)parent) {
	this->_order = 10;
}
Sysmod_Init_10::~Sysmod_Init_10() {

}
bool Sysmod_Init_10::invoke(Context &context) {
	std::cout << "Sysmod/Init/10 invoked!" << std::endl;
	return true;
}

