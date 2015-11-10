#include <string>
#include <stdlib.h>
#include <boost/any.hpp>

#include <soci.h>
#include <backends/sqlite3/soci-sqlite3.h>
#include "bd/be-designer.h"
#include "project.h"

using namespace std;
using namespace bd;
using namespace tst;

#define _TST_EVENT
#ifdef _TST_SOCI

int testSoci() {
	soci::session sql(*soci::factory_sqlite3(), "demo/tst.db");
	{		
		std::string name;
		sql <<"select inr from tst", soci::into(name);
		cout << name << endl;
		/*sql << "insert into cpp(inr, remark) values(:INR, :REMARK)"
			, soci::use(std::string("XXXXXXXX"))
			, soci::use(std::string("Hello Soci:ÄãºÃ"));
			*/
		std::vector<std::string> list(100);
		CppEntity entity;
		sql << "select inr from cpp", soci::into(list);
		cout << list.size() << endl;
	}

	return 1;
}
#endif

#include <iostream>
#include <vector>
#include <map>
#include <boost/thread.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <windows.h>

int main(int argc, char* argv[]){
	Logger::init();
	Logger::_info("Programe started");
#ifdef _TST_SOCI
	testSoci();
#elif defined _TST_EVENT
	bd::Context context;
	Session* session = context.getSession();
	// test chain transaction
    session->chain(std::string("cpptst"), true);
    
    
	Datafield* btn = (Datafield*)session->getObject("cppgrp/btn");
	if (!btn) {
		cout << "Failed to get cppgrp/btn" << endl;
		return -1;
	}
	Event e(EventType::ON_CLICK);	
	
	//for (int i = 0; i < 10; i++)
	session->invokeEventRule(*btn, e);

	// test module/field data binding
	Module* m = (Module*)session->getObject("cppgrp/cpp");
	if (!m) {
		cout << "Failed to get cppgrp/cpp" << endl;
		return -1;
	}
	Cpptst* cpptst = (Cpptst*)session->getTransaction();
	cpptst->getCppgrp()->getCpp()->set_Inr(std::string("12345678"));
	cpptst->getCppgrp()->getCpp()->set_Remark(std::string("Remark ¹þ¹þ"));
	Datafield* d = (Datafield*)m->getObject("inr");
	cout << d->toString() << endl;
	Datafield* n = (Datafield*)m->getObject("number");
	n->setValue(8087);
	cout << n->toString() << endl;

	std::map<std::string, Attribute*> modified = context.getPresentation()->getModifiedList();
	std::map<std::string, Attribute*>::iterator it;
	for (it = modified.begin(); it != modified.end(); it++) {
		cout << (string)(it->first) << endl;;
	}
#elif defined _TST_SYSMOD	
	bd::Context context;
	Session* session = context.getSession();
	session->chain(std::string("cpptst"), true);
	Datafield* m = (Datafield*)session->getObject("cppgrp/cpp/inr");
	Datafield* sysmod = (Datafield*)session->getObject("sysmod/user");	
	session->chain(std::string("cpptst"), true);
#else	
	cout << "Done!" << endl;
	bd::Context context;
	Session* session = context.getSession();	
	Cpp cpp;
	context.getPersistence()->read((PersistenceAble*)&cpp, "where inr='11'");
	cout << ModuleUtils::getValue(*cpp.get_Inr()) << " " << ModuleUtils::getValue(*cpp.get_Remark()) << endl;
	//
	CppList list;
	list.add(cpp);
	list.clear();
	context.getPersistence()->readSet(&list, "where inr in('11', '222')");
	cout << list.size() << endl;
#endif
	Logger::_debug("Programe finished");
	system("pause");
	return 0;
}
