#include "attribute.h"

#include <map>
#include <string>

bd::Attribute::Attribute(){
}

bd::Attribute::~Attribute(){
    this->_attrMap.clear();
}

std::string bd::Attribute::getAttribute(const std::string &attribute) const{
    std::map<const std::string, std::string>::const_iterator iter = this->_attrMap.find(attribute);
    if (iter != this->_attrMap.end()){
        return iter->second;
    }
    return NULL;
}

void bd::Attribute::setAttribute(const std::string &attrName, const std::string &value){
    this->_attrMap.insert(std::pair<const std::string, std::string>(attrName, value));
}