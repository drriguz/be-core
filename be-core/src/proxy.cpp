#include "bd/proxy.h"
using namespace bd;

ProxyModule::ProxyModule():_host(NULL){
}

ProxyModule::~ProxyModule(){
}

Module * ProxyModule::getHost(){
	return this->_host;
}

void ProxyModule::setHost(Module * module){
	this->_host = module;
}
