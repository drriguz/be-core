
#include "bd/be-designer.h"
#include "Cpp.h"
#include "Cppgrp.h"
#include "CppList.h"

#include <iostream>
using namespace bd;
using namespace tst;

Cppgrp::Cppgrp() {
	this->_cpp = new Cpp();
	this->_cpplst = new CppList();
	this->_cppgrp_init_1000 = new Cppgrp_Init_1000(this);
	this->_cppgrp_btn_event_100 = new Cppgrp_btn_event_100(this);
	this->_btn = new Datafield(typeid(std::string).name());
	this->_tmp = new Datafield(typeid(int).name());
	this->addChild();
}
Cppgrp::~Cppgrp() {
	if (this->_cpp)
		delete this->_cpp;
	if (this->_cpplst)
		delete this->_cpplst;
	if (this->_btn)
		delete this->_btn;
	if (this->_tmp)
		delete this->_tmp;
	if (this->_cppgrp_init_1000)
		delete this->_cppgrp_init_1000;
	if (this->_cppgrp_btn_event_100)
		delete this->_cppgrp_btn_event_100;
}
void Cppgrp::addChild() {
	if (!this->_childAdded) {
		this->_modules.insert(std::make_pair(std::string("cpp"), this->_cpp));
		this->_modules.insert(std::make_pair(std::string("cpplst"), this->_cpplst));
		this->_datafields.insert(std::make_pair(std::string("btn"), this->_btn));
		this->_datafields.insert(std::make_pair(std::string("tmp"), this->_tmp));
		this->_cpp->addChild();
		this->_childAdded = true;
	}
}
void Cppgrp::bindRules(Context *context) {
	if (!this->_eventBinded) {
		context->getRootModule()->addInitRule(this->_cppgrp_init_1000);
		this->_btn->addEventRule(_cppgrp_btn_event_100);
		this->_cpp->bindRules(context);
		this->_cpplst->bindRules(context);
		this->_eventBinded = true;
	}
}
Cpp* Cppgrp::getCpp() {
	return this->_cpp;
}
CppList* Cppgrp::getCppList() {
	return this->_cpplst;
}
void Cppgrp::set_Btn(const std::string &value) {
	this->_btn->setValue(value);
}
Datafield* Cppgrp::get_Btn() {
	return this->_btn;
}
void Cppgrp::set_Tmp(int value) {
	this->_tmp->setValue(value);
}
Datafield* Cppgrp::get_Tmp() {
	return this->_tmp;
}
//
Cppgrp_Init_1000::Cppgrp_Init_1000(Cppgrp* parent) :Rule((Module*)parent) {
	this->_order = 1000;
}
Cppgrp_Init_1000::~Cppgrp_Init_1000() {

}
bool Cppgrp_Init_1000::invoke(Context &context) {
	std::cout << "Cppgrp/Init/100 invoked!" << std::endl;
	CppList *cpplst = ((Cppgrp*)this->_parent)->getCppList();
	return true;
}
//
Cppgrp_btn_event_100::Cppgrp_btn_event_100(Cppgrp* parent) :EventRule((Module*)parent) {
	this->_type = EventType::ON_CLICK;
	this->_order = 100;
}
Cppgrp_btn_event_100::~Cppgrp_btn_event_100() {

}
bool Cppgrp_btn_event_100::invoke(Context &context, Event eventType) {
	std::cout << "Cppgrp/btn/onClick/100 invoked!" << std::endl;
	((Cppgrp*)this->_parent)->set_Tmp(ModuleUtils::getIntValue(*((Cppgrp*)this->_parent)->get_Tmp()) + 1);
	((Cppgrp*)this->_parent)->getCpp()->set_Number(ModuleUtils::getIntValue(*((Cppgrp*)this->_parent)->get_Tmp()));
	context.getPresentation()->setModified("cppgrp/cpp/number", (Attribute*)((Cppgrp*)this->_parent)->getCpp()->get_Number());

	((Cppgrp*)this->_parent)->getCpp()->set_Inr("XXXXXXXX");
	((Cppgrp*)this->_parent)->getCpp()->set_Remark("Hello Soci:ÄãºÃ");
	context.getPersistence()->begin();
	context.getPersistence()->save(((Cppgrp*)this->_parent)->getCpp());
	context.getPersistence()->commit();
	std::cout << "saved!" << std::endl;
	return true;
}
