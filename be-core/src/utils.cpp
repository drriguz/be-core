#include "utils.h"
#include "Rule.h"
#include "EventRule.h"
#include "module.h"

#include <boost\format.hpp>
#include <boost\tokenizer.hpp>
#include <boost\algorithm\\string.hpp>

using namespace bd;

void RuleUtils::sort(std::list<Rule> &list){
    list.sort();
}

void RuleUtils::sort(std::list<EventRule> &list){
    list.sort();
}

bool UrlUtils::getSubPath(const std::string &url, std::vector<std::string> &result){
    boost::split(result, url, boost::is_any_of("/\\"));
    return true;
}

bool RuleUtils::invokeInitRule(Module* root, Context &context){
    if (!root)
        return false;
    std::map<std::string, Module*> children = root->getModules();
    root->init(context);
    std::map<std::string, Module*>::iterator it;
    for (it = children.begin(); it != children.end(); ++it){
        if (!invokeInitRule(it->second, context))
            return false;
    }
    return true;
}