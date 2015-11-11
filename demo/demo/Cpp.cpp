
#include "bd/be-designer.h"
#include <string>
#include <soci.h>
#include <vector>
#include "Cpp.h"

using namespace bd;
using namespace tst;

Cpp::Cpp() {
	this->_inr = new Datafield(typeid(std::string).name());
	this->_remark = new Datafield(typeid(std::string).name());
	this->_number = new Datafield(typeid(int).name());
}
Cpp::Cpp(const Cpp& cpp) {
	this->_inr = new Datafield(*cpp._inr);
	this->_remark = new Datafield(*cpp._remark);
	this->_number = new Datafield(*cpp._number);
}
Cpp::~Cpp() {
	if (this->_inr)
		delete this->_inr;
	if (this->_remark)
		delete this->_remark;
	if (this->_number)
		delete this->_number;
	if (this->_entity)
		delete this->_entity;
}
void Cpp::addChild() {
	if (!this->_childAdded) {
		this->_datafields.insert(std::make_pair(std::string("inr"), this->_inr));
		this->_datafields.insert(std::make_pair(std::string("remark"), this->_remark));
		this->_datafields.insert(std::make_pair(std::string("number"), this->_number));
		this->_childAdded = true;
	}
}
void Cpp::bindRules(Context *context) {

}
Entity* Cpp::createObject() {
	CppEntity *entity = new CppEntity();
	entity->inr = ModuleUtils::getValue(*this->_inr);
	entity->remark = ModuleUtils::getValue(*this->_remark);
	return entity;
}
bool Cpp::fromObject(Entity* entity) {
	CppEntity *cppEntity = (CppEntity*)entity;
	this->set_Inr(cppEntity->inr);
	this->set_Remark(cppEntity->remark);
	return true;
}

Entity* Cpp::read(soci::session &sql, const std::string &whereClause) {
	CppEntity *entity = new CppEntity();
	entity->read(sql, whereClause);
	return entity;
}

std::vector<Entity*>* Cpp::readSet(soci::session &sql, const std::string &whereClause) {
	CppEntity entity;
	return entity.readSet(sql, whereClause);
}

void Cpp::set_Inr(const std::string & value) {
	this->_inr->setValue(value);
}
void Cpp::set_Remark(const std::string &value) {
	this->_remark->setValue(value);
}
void Cpp::set_Number(int value) {
	this->_number->setValue(value);
}

Datafield* Cpp::get_Inr() {
	return this->_inr;
}
Datafield* Cpp::get_Remark() {
	return this->_remark;
}
Datafield* Cpp::get_Number() {
	return this->_number;
}


bool CppEntity::save(soci::session &sql) {
	sql << "insert into cpp(inr, remark) values(:INR, :REMARK)"
		, soci::use(inr)
		, soci::use(remark);
	return true;
}

bool CppEntity::read(soci::session &sql, const std::string &whereClause) {
	sql << "select * from cpp " + whereClause, soci::into(*this);
	return true;
}

std::vector<Entity*>* CppEntity::readSet(soci::session &sql, const std::string &whereClause) {
	std::vector<std::string> vInr(1000);
	std::vector<std::string> vRemark(1000);
	sql << "select inr,remark from cpp " + whereClause, soci::into(vInr), soci::into(vRemark);
	std::vector<Entity*> *list = new std::vector<Entity*>();
	for (int i = 0; i < vInr.size(); i++) {
		CppEntity* item = new CppEntity();
		item->inr = vInr.at(i);
		item->remark = vInr.at(i);
		list->push_back(item);
	}
	return list;
}