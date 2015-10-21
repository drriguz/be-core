#include "bd/eventRule.h"
#include "bd/utils.h"

using namespace bd;

EventRule::EventRule(Module* parent):Rule(parent){
	
}

EventRule::~EventRule(){

}

bool EventRule::invoke(Context &context, Event eventType){
    return true;
}

EventType  EventRule::getEventType() {
	return this->_type;
}
EventAble::EventAble() :_ruleSorted(false) {

}
EventAble::~EventAble() {

}
void EventAble::addEventRule(EventRule *rule) {
	this->_eventRuleList.push_back(rule);
	this->_ruleSorted = false;
}

void EventAble::sortRules() {
	RuleUtils::sort(this->_eventRuleList);
	RuleUtils::sort(this->_ruleList);
	this->_ruleSorted = true;
}


std::list<EventRule*>* EventAble::getEventRules() {
	return &this->_eventRuleList;
}