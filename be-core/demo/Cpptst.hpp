#ifndef _TST_CPPTST_HPP_
#define _TST_CPPTST_HPP_

#include "be-designer.h"

namespace bd{
    class Cpptst :public Transaction{
    public:
        Cpptst(){
            this->_b1 = new Datafield(typeid(std::string));
            this->_t1 = new Datafield(typeid(std::string));
        }
        ~Cpptst(){
            if (this->_b1)
                delete this->_b1;
            if (this->_t1)
                delete this->_t1;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_datafields.insert(std::make_pair(std::string("b1"), this->_b1));
                this->_datafields.insert(std::make_pair(std::string("t1"), this->_t1));
                this->_childAdded = true;
            }
        }
        void set_B1(const std::string & value){
            this->_b1->setValue(boost::any(value));
        }
        void set_T1(const std::string &value){
            this->_t1->setValue(boost::any(value));
        }
        std::string get_B1(){
            return boost::any_cast<std::string>(*this->_b1);
        }
        std::string get_T1(){
            return boost::any_cast<std::string>(*this->_t1);
        }
    protected:
        Datafield* _b1;
        Datafield* _t1;
    };
}
#endif