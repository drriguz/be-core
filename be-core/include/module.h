#ifndef _BE_DESIGNER_MODULE_H_
#define _BE_DESIGNER_MODULE_H_

#include "Object.h"

#include <map>
#include <string>
#include <list>

namespace bd{
    class Datafield;
}

namespace bd{
    class Module:public Object{
    public:
        Module();
        ~Module();
        Module(const Module& module);
    public:
        virtual void addChild();
        virtual bool isSelected();
        virtual bool isChildAdded();
        virtual bool isEventBinded();
        virtual std::map<std::string, Module*> getModules();
        virtual std::map<std::string, Datafield*> getDatafields();
    protected:
        std::map<std::string, Datafield*> _datafields;
        std::map<std::string, Module*> _modules;
        bool _selected;
        bool _childAdded;
        bool _eventBinded;
    };
}

#endif