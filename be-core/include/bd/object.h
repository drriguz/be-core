#ifndef _BE_DESIGNER_BASE_OBJECT_H_
#define _BE_DESIGNER_BASE_OBJECT_H_

#include <map>
#include <string>
#include <list>
#include <boost\any.hpp>

#include "attribute.h"

namespace bd{    
	class Rule;

    enum ObjectType{
        OBJECT,
        MODULE,
        DATAFIELD
    };

    class Object :public Attribute{
    public:
        Object();
        ~Object();
    public:
        std::string getName() const;
        std::string getUrl() const;
        void setName(const std::string &name);
        void setUrl(const std::string &url);        
        Object* getParent();
        void setParent(Object *parent);
        virtual std::string toString() const;
        virtual void clear();
        virtual bool isEmpty();
        virtual ObjectType getType();
		virtual void addInitRule(Rule *rule);
		virtual std::list<Rule*> getInitRules();
    protected:
        std::string _name;
        std::string _url;
        Object* _parent;
		std::list<Rule*> _initRules;
    };
}

#endif