#include "ModuleSupport.h"
using namespace bd;

ModuleSupport::ModuleSupport(){

}
ModuleSupport::~ModuleSupport(){

}
bool ModuleSupport::init() {
    return true;
}

bool ModuleSupport::invoke(void* callback){
    return true;
}
bool ModuleSupport::begin(){
    return true;
};
bool ModuleSupport::commit(){
    return true;
};
bool ModuleSupport::rollback(){
    return true;
};
int ModuleSupport::count(const char* key) {
    return 1;
};
bool ModuleSupport::lock(const char* key) {
    return true;
};
bool ModuleSupport::unlock(const char* key) {
    return true;
};
bool ModuleSupport::save(const Module *module) {
    return true;
};
bool ModuleSupport::update(const Module *Module) {
    return true;
};
bool ModuleSupport::reupdate(const Module *module) {
    return true;
};
bool ModuleSupport::remove(const Module *module) {
    return true;
};
bool ModuleSupport::get(Module *module) {
    return true;
}; 
bool ModuleSupport::execute(const char *sql, void* params, ...) {
    return true;
};
bool ModuleSupport::fetch() {
    return true;
};
bool ModuleSupport::close() {
    return true;
};