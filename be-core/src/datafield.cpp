#include "bd/datafield.h"
#include "bd/utils.h"
#include "bd/object.h"
#include "bd/context.h"
#include "bd/rule.h"
#include "bd/eventRule.h"

#include <boost\lexical_cast\lexical_cast_old.hpp>
using namespace bd;

Datafield::Datafield():_typeName(typeid(std::string).name()){
    
	
}

Datafield::Datafield(const type_info& type):_typeName(type.name()){   
	if (type == typeid(int))
		this->setValue(0);
}

Datafield::~Datafield(){
    if (this->_value)
        delete this->_value;
}

void Datafield::setValue(const std::string &value){
    if (this->_value)
        delete this->_value;
    this->_value = new boost::any(value);
}

boost::any* Datafield::getValue() const{
    return this->_value;
}

std::string Datafield::toString() const{
    if (this->_value->type() == typeid(int))
        return boost::lexical_cast<std::string>(boost::any_cast<int>(*this->_value));
    if (this->_value->type() == typeid(std::string))
        return boost::any_cast<std::string>(*this->_value);
    return NULL;
}

void Datafield::clear(){
    this->_value = NULL;
}

ObjectType Datafield::getType(){
    return ObjectType::DATAFIELD;
}

bool Datafield::invokeEventRules(Context &context, Event eventType) {
	if (!this->_ruleSorted)
		this->sortRules();
	return RuleUtils::invokeEventRule(this, &context, eventType);
}