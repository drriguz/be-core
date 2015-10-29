#ifndef _BE_DESIGNER_DATAFIELD_H_
#define _BE_DESIGNER_DATAFIELD_H_

#include <map>
#include <string>
#include <list>
#include <typeinfo>

#include "object.h"
#include "eventRule.h"

namespace bd{
    class Context;
    class Rule;
	enum EventType;
	class Event;
}

namespace bd{
    class Datafield:public Object, public EventAble{
    public:
        Datafield();
		Datafield(const Datafield& field);
        Datafield(const std::string& type);
        ~Datafield();
    public:
        virtual boost::any* getValue() const;        
        virtual void setValue(const std::string &value);

        template<typename  T>
        void setValue(T value){
            if (this->_value)
                delete this->_value;
            this->_value = new boost::any(value);
        }        
        virtual std::string toString() const;
        virtual void clear();
        virtual ObjectType getType();
		virtual bool invokeEventRules(Context &context, Event eventType);
	protected:
        boost::any* _value;
        std::string _typeName;
    };
}

#endif