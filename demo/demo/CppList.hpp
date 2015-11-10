#ifndef _TST_ENTITY_LIST_H_
#define _TST_ENTITY_LIST_H_

#include "bd/be-designer.h"
using namespace bd;

namespace tst {
	class CppList :public ModuleList,public ReadSetAble {
	public:
		CppList(){

		}
		~CppList(){

		}
	public:
		virtual bool add(Module &module) {
			Cpp& m = dynamic_cast<Cpp &> (module);
			Cpp *copy = new Cpp(m);
			this->_list.push_back(copy);
			return true;
		}

		virtual bool readSet(soci::session &sql, const std::string &whereClause) {
			Cpp cpp;
			std::vector<Entity*>* list = cpp.readSet(sql, whereClause);
			std::vector<Entity*>::iterator it;
			for (it = list->begin(); it != list->end(); it++) {
				Entity* e = *it;
				Cpp* c = new Cpp();
				c->fromObject(e);
				this->_list.push_back(c);
			}
			delete list;
			return true;
		}
	};
}

#endif