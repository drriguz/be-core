#ifndef _BE_DESIGNER_DATAFIELD_H_
#define _BE_DESIGNER_DATAFIELD_H_

#include <map>
#include <string>
#include <list>
#include <typeinfo>

#include "object.h"

namespace bd{
    class Context;
    class Rule;
    class EventRule;
}

namespace bd{
    class Datafield:public Object{
    public:
        Datafield();
        Datafield(const type_info& type);
        ~Datafield();
    public:
        void addEventRule(const EventRule &rule);        
        virtual bool invokeEventRules(Context &context);
        virtual boost::any* getValue() const;
        virtual void setValue(boost::any& value);
        virtual std::string toString() const;
        virtual void clear();
        virtual ObjectType getType();
    protected:
        void sortRules();
    protected:
        std::list<Rule> _ruleList;
        std::list<EventRule> _eventRuleList;
        bool _ruleSorted;
        boost::any* _value;
        std::string _typeName;
    };
}

#endif