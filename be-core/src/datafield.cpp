#include "datafield.h"
#include "utils.h"
#include "object.h"
#include "context.h"
#include "rule.h"
#include "eventRule.h"

#include <boost\lexical_cast\lexical_cast_old.hpp>
using namespace bd;

Datafield::Datafield():_typeName(typeid(std::string).name()){
    this->_ruleSorted = false;
	
}

Datafield::Datafield(const type_info& type):_typeName(type.name()){   
	if (type == typeid(int))
		this->setValue(0);
}

Datafield::~Datafield(){
    if (this->_value)
        delete this->_value;
}

void Datafield::addEventRule(EventRule *rule){
    this->_eventRuleList.push_back(rule);
    this->_ruleSorted = false;
}

void Datafield::sortRules(){
    RuleUtils::sort(this->_eventRuleList);
    RuleUtils::sort(this->_ruleList);
    this->_ruleSorted = true;
}

bool Datafield::invokeEventRules(Context &context, Event eventType){
    if (!this->_ruleSorted)
        this->sortRules();
	return RuleUtils::invokeEventRule(this, &context, eventType);
}
std::list<EventRule*>* Datafield::getEventRules() {
	return &this->_eventRuleList;
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