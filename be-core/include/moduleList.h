#ifndef _BE_DESIGNER_MODULE_LIST_H_
#define _BE_DESIGNER_MODULE_LIST_H_

#include <string>

#include "Module.h"

namespace bd{
    class ModuleList:public Module{
        virtual int size() = 0;
        virtual int getPageSize() = 0;
        virtual int getPageNumber() = 0;
        virtual bool add(const Module *module) = 0;
        virtual bool remove(int index) = 0;
        virtual bool remove(const Module *module) = 0;
    };
}

#endif