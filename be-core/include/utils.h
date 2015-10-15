#ifndef _BE_DESIGNER_RULE_UTILS_H_
#define _BE_DESIGNER_RULE_UTILS_H_

#include <map>
#include <string>
#include <vector>
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

    class UrlUtils{
    public:
        static bool getSubPath(const std::string &url, std::vector<std::string> &result);
    };
}
#endif