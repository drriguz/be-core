#include "ruleUtils.h"
#include "Rule.h"
#include "EventRule.h"

using namespace bd;

void RuleUtils::sort(std::list<Rule> &list){
    list.sort();
}

void RuleUtils::sort(std::list<EventRule> &list){
    list.sort();
}