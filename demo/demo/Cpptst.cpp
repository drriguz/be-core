#include "bd/be-designer.h"
#include "Cppgrp.h"
#include "Cpptst.h"
#include "Cpp.h"
#include "Sysmod.h"


using namespace bd;
using namespace tst;

Cpptst::Cpptst(Context* context) :Transaction() {
	this->_cppgrp = new Cppgrp();
	this->_cpptst_init_10 = new Cpptst_Init_10(this);
	this->_cppgrp_btn_event_500 = new Cpptst_btn_event_500(this);

	Module* sysmod = context->getSession()->getStaticModule("sysmod");
	if (sysmod)
		this->_sysmod = (Sysmod*)sysmod;
	else {
		this->_sysmod = new Sysmod();
		context->getSession()->setStaticModule("sysmod", this->_sysmod);
	}
}
Cpptst::~Cpptst() {
	if (this->_cppgrp)
		delete this->_cppgrp;
	if (this->_cpptst_init_10)
		delete this->_cpptst_init_10;
	if (this->_cppgrp_btn_event_500)
		delete this->_cppgrp_btn_event_500;
}
void Cpptst::addChild() {
	if (!this->_childAdded) {
		this->_modules.insert(std::make_pair(std::string("cppgrp"), this->_cppgrp));
		this->_cppgrp->addChild();
		this->_sysmod->addChild();
		this->_childAdded = true;
	}
}
void Cpptst::bindRules(Context *context) {
	if (!this->_eventBinded) {
		context->getRootModule()->addInitRule(this->_cpptst_init_10);
		this->getCppgrp()->get_Btn()->addEventRule(this->_cppgrp_btn_event_500);
		this->_cppgrp->bindRules(context);
		this->_sysmod->bindRules(context);
		this->_eventBinded = true;
	}
}
Cppgrp* Cpptst::getCppgrp() {
	return this->_cppgrp;
}
//
Cpptst_Init_10::Cpptst_Init_10(Cpptst *parent) :Rule((Module*)parent) {
	this->_order = 10;
}
Cpptst_Init_10::~Cpptst_Init_10() {

}
bool Cpptst_Init_10::invoke(Context &context) {
	std::cout << "Cpptst/Init/10 invoked!" << std::endl;
	return true;
}
//
Cpptst_btn_event_500::Cpptst_btn_event_500(Cpptst *parent) :EventRule((Module*)parent) {
	this->_type = EventType::ON_CLICK;
	this->_order = 500;
}
Cpptst_btn_event_500::~Cpptst_btn_event_500() {

}
bool Cpptst_btn_event_500::invoke(Context &context, Event eventType) {
	std::cout << "Cpptst/btn/onClick/500 invoked!" << std::endl;
	Cpptst* cpptst = (Cpptst*)this->_parent;
	int tmp = ModuleUtils::getIntValue(*cpptst->getCppgrp()->get_Tmp());
	std::cout << "Tmp=" << tmp << std::endl;
	return true;
}
//