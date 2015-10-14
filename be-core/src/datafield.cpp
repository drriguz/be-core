#include "datafield.h"
#include "ruleUtils.h"
#include "Object.h"
#include "Context.h"
#include "Rule.h"
#include "EventRule.h"

#include <boost\lexical_cast\lexical_cast_old.hpp>
using namespace bd;

Datafield::Datafield():_typeName(typeid(std::string).name()){
    this->_ruleSorted = false;
}

Datafield::Datafield(const type_info& type):_typeName(type.name()){
    
}

Datafield::~Datafield(){

}

void Datafield::addEventRule(const EventRule &rule){
    this->_eventRuleList.push_back(rule);
    this->_ruleSorted = false;
}

void Datafield::sortRules(){
    RuleUtils::sort(this->_eventRuleList);
    RuleUtils::sort(this->_ruleList);
    this->_ruleSorted = true;
}

bool Datafield::invokeEventRules(Context &context){
    if (!this->_ruleSorted)
        this->sortRules();
    return true;
}

void Datafield::setValue(boost::any& value){
    this->_value = &value;
}

boost::any* Datafield::getValue() const{
    return this->_value;
}

std::string Datafield::toString() const{
    if (this->_value->type() == typeid(int))
        return boost::lexical_cast<std::string>(boost::any_cast<int>(*this->_value));
    if (this->_value->type() == typeid(std::string))
        return boost::any_cast<std::string>(*this->_value);
    if (this->_value->type() == typeid(std::string))
        return boost::any_cast<std::string>(*this->_value);
    return NULL;
}

void Datafield::clear(){
    this->_value = NULL;
}