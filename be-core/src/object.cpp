#include "Object.h"

#include <map>
#include <string>
#include <boost\any.hpp>


bd::Object::Object(){

}

bd::Object::~Object(){
    //if (this->_value != NULL)
    //    delete this->_value;
}

std::string bd::Object::getName() const{
    return this->_name;
}

std::string bd::Object::getUrl() const{
    return this->_url;
}

void bd::Object::setName(const std::string &name){
    this->_name = name;
}

void bd::Object::setUrl(const std::string &url){
    this->_url = url;
}

bd::Object* bd::Object::getParent(){
    return this->_parent;
}



void bd::Object::setParent(bd::Object *parent){
    this->_parent = parent;
}

void bd::Object::clear(){
    //this->_value = NULL;
}

std::string bd::Object::toString() const{
    
    return std::string();
}

bool bd::Object::isEmpty(){
    //return this->_value == NULL;
    return NULL;
}