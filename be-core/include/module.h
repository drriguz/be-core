#ifndef _BE_DESIGNER_MODULE_H_
#define _BE_DESIGNER_MODULE_H_

#include "object.h"

#include <map>
#include <string>
#include <list>

namespace bd{
    class Datafield;
    class EventRule;
    class Rule;
    class Context;
}

namespace bd{
    class Module:public Object{
    public:
        Module();
        ~Module();
        Module(const Module& module);
    public:
        virtual void addChild();
        virtual void bindRules(Context *context);
        virtual bool isSelected();
        virtual bool isChildAdded();
        virtual bool isEventBinded();
        virtual std::map<std::string, Module*> getModules();
        virtual std::map<std::string, Datafield*> getDatafields();
        virtual Object* getObject(const std::string &url);
        virtual ObjectType getType();
    protected:
        std::map<std::string, Datafield*> _datafields;
        std::map<std::string, Module*> _modules;
        std::list<EventRule*> _eventRules;
        std::list<Rule*> _rules;
        bool _selected;
        bool _childAdded;
        bool _eventBinded;
    };
}

#endif