#include "object.h"
#include "rule.h"

#include <map>
#include <string>
#include <boost\any.hpp>
using namespace bd;

Object::Object(){

}

Object::~Object(){
    //if (this->_value != NULL)
    //    delete this->_value;
}

std::string Object::getName() const{
    return this->_name;
}

std::string Object::getUrl() const{
    return this->_url;
}

void Object::setName(const std::string &name){
    this->_name = name;
}

void Object::setUrl(const std::string &url){
    this->_url = url;
}

Object* Object::getParent(){
    return this->_parent;
}



void Object::setParent(Object *parent){
    this->_parent = parent;
}

void Object::clear(){
    //this->_value = NULL;
}

std::string Object::toString() const{
    
    return std::string();
}

bool Object::isEmpty(){
    //return this->_value == NULL;
    return NULL;
}

ObjectType Object::getType(){
    return ObjectType::OBJECT;
}
void Object::addInitRule(Rule *rule) {
	this->_initRules.push_back(rule);
}

std::list<Rule*> Object::getInitRules() {
	return this->_initRules;
}