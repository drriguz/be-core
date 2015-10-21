#include "Events.h"
#include "project.h"
#include "bd/attribute.h"
using namespace bd;

Cppgrp_Init_1000::Cppgrp_Init_1000(Cppgrp* parent) :Rule((Module*)parent) {
	this->_order = 1000;
}
Cppgrp_Init_1000::~Cppgrp_Init_1000() {

}
bool Cppgrp_Init_1000::invoke(Context &context) {
	std::cout << "Cppgrp/Init/100 invoked!" << std::endl;
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
	int tmp = ModuleUtils::getIntValue(*((Cppgrp*)this->_parent)->get_Tmp());
	((Cppgrp*)this->_parent)->set_Tmp(tmp + 1);
	context.getPresentation()->setModified((Attribute*)((Cppgrp*)this->_parent)->get_Tmp());
	return true;
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
	std::cout <<"Tmp=" << tmp << std:: endl;
	return true;
}