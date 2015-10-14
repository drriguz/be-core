#ifndef _BE_DESIGNER_MODULE_SESSION_H_
#define _BE_DESIGNER_MODULE_SESSION_H_

#include "Context.h"

#include <string>
#include <list>

namespace bd{
    class AbstractModuleSession{
    public:
        virtual bool isDirectCall();
        virtual bool isReturnCall();
        virtual bool isHomeTrans();
        virtual std::list<std::string> getTransactionStack();
    protected:
        Context _context;
    };
}

#endif