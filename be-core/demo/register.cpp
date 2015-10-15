#include "register.h"
#include "transaction.h"
#include "project.h"

using namespace bd;

Register::Register(){

}

Register::~Register(){

}

bool Register::createTransaction(const std::string &name, Transaction* &trans){
    if (name == "cpptst"){
        trans = new Cpptst();
        return true;
    }
    return false;
}