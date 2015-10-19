#include "rule.h"
#include "module.h"
using namespace bd;

Rule::Rule(Module* parent):_parent(parent){

}

Rule::~Rule(){

}

int Rule::getOrder(){
    return this->_order;
}


void Rule::setOrder(int order){
    this->_order = order;
}

bool Rule::invoke(Context &context){
    return true;
}

bool Rule::operator < (const Rule &m) const{
    return m._order < this->_order;
}