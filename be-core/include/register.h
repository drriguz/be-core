#ifndef _BE_DESIGNRE_REGISTER_H_
#define _BE_DESIGNRE_REGISTER_H_

#include <map>
#include <string>

namespace bd{
    class Module;
    class Transaction;
}
namespace bd{
    class Register{
    public:
        Register();
        ~Register();
    public:
        static bool createTransaction(const std::string &name, Transaction* trans);
    };
}
#endif