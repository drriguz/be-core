#ifndef _BE_DESIGNER_EVENT_RULE_H_
#define _BE_DESIGNER_EVENT_RULE_H_

#include "Context.h"
#include "Rule.h"
#include "event.h"

namespace bd{
    class EventRule :public Rule{
    public:
        EventRule();
        ~EventRule();
    public:
        virtual bool invoke(Context &context, Event eventType);
    };
}

#endif