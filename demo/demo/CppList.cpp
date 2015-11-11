

#include "bd/be-designer.h"
#include "Cpp.h"
#include "CppList.h"
using namespace bd;
using namespace tst;


CppList::CppList() {

}
CppList::~CppList() {

}
bool CppList::add(Module &module) {
	Cpp& m = dynamic_cast<Cpp &> (module);
	Cpp *copy = new Cpp(m);
	this->_list.push_back(copy);
	return true;
}

bool CppList::readSet(soci::session &sql, const std::string &whereClause) {
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
