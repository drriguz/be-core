#include "bd/utils.h"
#include "bd/rule.h"
#include "bd/eventRule.h"
#include "bd/module.h"
#include "bd/datafield.h"
#include "bd/event.h"

#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

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
		if (!r->invoke(context))
			break;
	}
	return true;
}
bool RuleUtils::invokeEventRule(EventAble *field, Context *context, Event eventType) {
	if (!field)
		return false;
	if (!context)
		return false;
	std::list<EventRule*> *rules = field->getEventRules();
	std::list<EventRule*>::iterator it;
	for (it = rules->begin(); it != rules->end(); it++) {		
		EventRule* r = *it;
		if (eventType.getEventType() == r->getEventType()) {
			if (!r->invoke(*context, eventType))
				break;
		}
	}
	return true;
}

int ModuleUtils::getIntValue(Datafield &d) {
	return boost::any_cast<int>(*d.getValue());
}
std::string ModuleUtils::getValue(Datafield &d) {
	return boost::any_cast<std::string>(*d.getValue());
}