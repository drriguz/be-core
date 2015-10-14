#include "Rule.h"
using namespace bd;

Rule::Rule(){

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