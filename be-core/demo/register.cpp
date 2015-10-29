#include "bd/register.h"
#include "bd/transaction.h"
#include "bd/context.h"
#include "project.h"

using namespace bd;
using namespace tst;

Register::Register(){

}

Register::~Register(){

}

bool Register::createTransaction(const std::string &name, Transaction* &trans, Context &ctx){
    if (name == "cpptst"){
        trans = new Cpptst(&ctx);
        return true;
    }
    return false;
}