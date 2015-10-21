#include <iostream>
#include <string>
#include <stdlib.h>
#include <boost/any.hpp>

#include "bd/be-designer.h"
#include "project.h"

using namespace std;
using namespace bd;
using namespace boost;


int main(int argc, char* argv[]){
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
	
	for (int i = 0; i < 10; i++)
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
	cout << "Done!" << endl;
    system("pause");
    return 0;
}