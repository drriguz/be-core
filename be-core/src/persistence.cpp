#include "bd/persistence.h"
#include "bd/module.h"
#include "bd/moduleList.h"
#include <soci.h>
#include <backends/sqlite3/soci-sqlite3.h>
using namespace bd;

std::string connectString = "demo/tst.db";
const soci::backend_factory  &backEnd = *soci::factory_sqlite3();

Persistence::Persistence(){

}
Persistence::~Persistence(){
	if (this->_session)
		delete this->_session;
	if (this->_transaction)
		delete this->_transaction;
}
bool Persistence::init() {
    return true;
}

bool Persistence::invoke(void* callback){
    return true;
}
bool Persistence::begin(){
	if (this->_session)
		delete this->_session;
	if (this->_transaction)
		delete this->_transaction;
	this->_session = new soci::session(backEnd, connectString);
	this->_transaction = new soci::transaction(*this->_session);
	//this->_session->begin();
    return true;
};
bool Persistence::commit(){
	if (this->_transaction) {
		this->_transaction->commit();
		delete this->_transaction;
		if (this->_session)
			delete this->_session;
		this->_session = NULL;
		this->_transaction = NULL;
	}
    return true;
};
bool Persistence::rollback(){
    return true;
};
int Persistence::count(const char* key) {
    return 1;
};
bool Persistence::lock(const char* key) {
    return true;
};
bool Persistence::unlock(const char* key) {
    return true;
};
bool Persistence::save(PersistenceAble *module) {
	if (!this->_session)
		return false;
	PersistenceAble*p = (PersistenceAble*)module;
	Entity* e = p->createObject();
	{
		//soci::session soci_session(backEnd, connectString);
		e->save(*this->_session);
	}
	delete e;
    return true;
};
bool Persistence::update(const Module *Module) {
    return true;
};
bool Persistence::reupdate(const Module *module) {
    return true;
};
bool Persistence::remove(const Module *module) {
    return true;
};
bool Persistence::get(Module *module) {
    return true;
}; 
bool Persistence::execute(const char *sql, void* params, ...) {
    return true;
};
bool Persistence::fetch() {
    return true;
};
bool Persistence::close() {
    return true;
};

bool Persistence::read(PersistenceAble* module, const std::string& whereClause) {
	soci::session sql(backEnd, connectString);
	PersistenceAble *p = (PersistenceAble*)module;
	Entity* e = p->read(sql, whereClause);
	p->fromObject(e);
	delete e;
	return true;
}
bool Persistence::readSet(ReadSetAble* list, const std::string& whereClause) {
	soci::session sql(backEnd, connectString);
	list->readSet(sql, whereClause);
	return true;
}