#include "module.h"
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