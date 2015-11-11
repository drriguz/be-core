#ifndef _TST_ENTITY_LIST_H_
#define _TST_ENTITY_LIST_H_

#include "bd/be-designer.h"
using namespace bd;

namespace tst {
	class CppList :public ModuleList,public ReadSetAble {
	public:
		CppList();
		~CppList();
	public:
		virtual bool add(Module &module);
		virtual bool readSet(soci::session &sql, const std::string &whereClause);
	};
}

#endif