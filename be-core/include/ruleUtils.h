#ifndef _BE_DESIGNER_RULE_UTILS_H_
#define _BE_DESIGNER_RULE_UTILS_H_

#include <map>
#include <string>
#include <list>

namespace bd{
    class Rule;
    class EventRule;
}

namespace bd{
    class RuleUtils{
    public:
        static void sort(std::list<Rule> &list);
        static void sort(std::list<EventRule> &list);
    };
}
#endif