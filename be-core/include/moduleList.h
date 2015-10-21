#ifndef _BE_DESIGNER_MODULE_LIST_H_
#define _BE_DESIGNER_MODULE_LIST_H_

#include <string>
#include <vector>

#include "module.h"
#include "eventRule.h"

namespace bd{
    class ModuleList:public Module, public EventAble{
	public:
		ModuleList();
		ModuleList(const ModuleList &t);
		~ModuleList();
	public:
        virtual int size();
        virtual int getPageSize();
        virtual int getPageNumber();
        virtual bool add(const Module &module);		
        virtual bool remove(int index);
		virtual Module* get(int i);
		virtual void clear();
		virtual bool invokeEventRules(Context &context, Event eventType);
	protected:
		std::vector<Module*> _list;
		int _pageSize;
		int _currentPage;
    };
}

#endif