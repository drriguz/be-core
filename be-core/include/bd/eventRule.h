#ifndef _BE_DESIGNER_EVENT_RULE_H_
#define _BE_DESIGNER_EVENT_RULE_H_

#include "context.h"
#include "rule.h"
#include "event.h"

#include <list>

namespace bd{
    class EventRule :public Rule{
    public:
        EventRule(Module* parent);
        ~EventRule();
    public:
        virtual bool invoke(Context &context, Event eventType);
		virtual EventType getEventType();
    protected:
        EventType _type;
    };

	class EventAble {
	public:
		EventAble();
		~EventAble();
	public:
		virtual void addEventRule(EventRule *rule);
		virtual bool invokeEventRules(Context &context, Event eventType)=0;
		virtual std::list<EventRule*>* getEventRules();
	protected:
		void sortRules();
	protected:
		std::list<Rule*> _ruleList;
		std::list<EventRule*> _eventRuleList;
		bool _ruleSorted;
	};
}

#endif