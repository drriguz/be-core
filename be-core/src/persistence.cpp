#include "bd/persistence.h"
#include <soci.h>
#include <backends/sqlite3/soci-sqlite3.h>
using namespace bd;

std::string connectString = "demo/tst.db";
const soci::backend_factory  &backEnd = *soci::factory_sqlite3();

Persistence::Persistence(){

}
Persistence::~Persistence(){

}
bool Persistence::init() {
    return true;
}

bool Persistence::invoke(void* callback){
    return true;
}
bool Persistence::begin(){
    return true;
};
bool Persistence::commit(){
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
	PersistenceAble*p = (PersistenceAble*)module;
	Entity* e = p->createObject();
	{
		soci::session soci_session(backEnd, connectString);
		e->save(soci_session);
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