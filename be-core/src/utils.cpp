#include "utils.h"
#include "Rule.h"
#include "EventRule.h"
#include "module.h"
#include "datafield.h"
#include "event.h"

#include <boost\format.hpp>
#include <boost\tokenizer.hpp>
#include <boost\algorithm\\string.hpp>

using namespace bd;

void RuleUtils::sort(std::list<Rule*> &list){
    list.sort();
}

void RuleUtils::sort(std::list<EventRule*> &list){
    list.sort();
}

bool UrlUtils::getSubPath(const std::string &url, std::vector<std::string> &result){
    boost::split(result, url, boost::is_any_of("/\\"));
    return true;
}

bool RuleUtils::invokeInitRule(Module* root, Context &context){
    if (!root)
        return false;
	std::list<Rule*> rules = root->getInitRules();
	std::list<Rule*>::iterator it;
	for (it = rules.begin(); it != rules.end(); it++) {
		Rule* r = *it;
		r->invoke(context);
	}
	return true;
}
bool RuleUtils::invokeEventRule(Datafield *field, Context *context, Event eventType) {
	if (!field)
		return false;
	if (!context)
		return false;
	std::list<EventRule*> *rules = field->getEventRules();
	std::list<EventRule*>::iterator it;
	for (it = rules->begin(); it != rules->end(); it++) {
		EventRule* r = *it;
		r->invoke(*context, eventType);
	}
	return true;
}

int ModuleUtils::getIntValue(Datafield &d) {
	return boost::any_cast<int>(*d.getValue());
}
std::string ModuleUtils::getValue(Datafield &d) {
	return boost::any_cast<std::string>(*d.getValue());
}