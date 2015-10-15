#include "module.h"
#include "eventRule.h"
#include "datafield.h"
#include "rule.h"

using namespace bd;

Module::Module() :_selected(false), _childAdded(false), _eventBinded(false){

}

Module::~Module(){

}

Module::Module(const Module& module){

}

void Module::addChild(){

}

bool Module::isSelected(){
    return this->_selected;
}

bool Module::isChildAdded(){
    return this->_childAdded;
}

bool Module::isEventBinded(){
    return this->_eventBinded;
}

std::map<std::string, Module*> Module::getModules(){
    return this->_modules;
}

std::map<std::string, Datafield*> Module::getDatafields(){
    return this->_datafields;
}

ObjectType Module::getType(){
    return ObjectType::MODULE;
}

Object* Module::getObject(const std::string &url){
    Module* m = this->_modules[url];
    if (m)
        return m;
    Datafield* d = this->_datafields[url];
    if (d)
        return d;
    return NULL;
}

void Module::bindRules(){

}

bool Module::init(Context &context){
    return true;
}