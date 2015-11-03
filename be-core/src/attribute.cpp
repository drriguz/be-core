#include "bd/attribute.h"

#include <map>
#include <string>

using namespace bd;

Attribute::Attribute(){
}

Attribute::~Attribute(){
    this->_attrMap.clear();
}

std::string Attribute::getAttribute(const std::string &attribute) const{
    std::map<const std::string, std::string>::const_iterator iter = this->_attrMap.find(attribute);
    if (iter != this->_attrMap.end()){
        return iter->second;
    }
    return NULL;
}

void Attribute::setAttribute(const std::string &attrName, const std::string &value){
    this->_attrMap.insert(std::pair<const std::string, std::string>(attrName, value));
}

void Attribute::clear() {
	this->_attrMap.clear();
}