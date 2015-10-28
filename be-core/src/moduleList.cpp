#include "bd/moduleList.h"
#include "bd/utils.h"
using namespace bd;

ModuleList::ModuleList() {

}

ModuleList::ModuleList(const ModuleList &t) {
	for (int i = 0; i < t._list.size(); i++) {
		Module *m = new Module(*t._list[i]);
		this->_list.push_back(m);
	}
}

ModuleList::~ModuleList() {
	this->clear();
}

int ModuleList::size() {
	return this->_list.size();
}

int ModuleList::getPageSize() {
	return this->_pageSize;
}

int ModuleList::getPageNumber() {
	return this->_currentPage;
}

bool ModuleList::add(Module &module) {
	Module* m = new Module(module);
	this->_list.push_back(m);
	return true;
}

bool ModuleList::remove(int index) {
	if (index <0 || index > this->_list.size())
		return false;
	Module* m = this->_list[index];
	if (m)
		delete m;
	this->_list.erase(this->_list.begin() + index);
	return true;
}

Module* ModuleList::get(int i) {
	if (i <0 || i > this->_list.size())
		return NULL;
	return this->_list[i];
}

void ModuleList::clear() {	
	for (int i = 0; i < this->_list.size(); i++) {
		if (this->_list[i]) {
			Module* m = this->_list[i];
			if(m){
				delete m;
				m = NULL;
			}
			
		}
	}
	this->_list.clear();
}

bool ModuleList::invokeEventRules(Context &context, Event eventType) {
	if (!this->_ruleSorted)
		this->sortRules();
	return RuleUtils::invokeEventRule(this, &context, eventType);
}