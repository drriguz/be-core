#ifndef _BE_DESIGNER_RULE_UTILS_H_
#define _BE_DESIGNER_RULE_UTILS_H_

#include <map>
#include <string>
#include <vector>
#include <list>
#include <boost\any.hpp>

namespace bd{
    class Rule;
    class EventRule;
    class Module;
    class Context;
	class Event;
	class Datafield;
	class EventAble;
}

namespace bd{
    class RuleUtils{
    public:
        static void sort(std::list<Rule*> &list);
        static void sort(std::list<EventRule*> &list);
        static bool invokeInitRule(Module *root, Context &context);
		static bool invokeEventRule(EventAble *field, Context *context, Event eventType);
    };

	class ModuleUtils {
	public:
		static int getIntValue(Datafield &d);
		static std::string getValue(Datafield &d);
	};
    class UrlUtils{
    public:
        static bool getSubPath(const std::string &url, std::vector<std::string> &result);
    };
}
#endif