#ifndef _TST_CPP_HPP_H_
#define _TST_CPP_HPP_H_

#include "be-designer.h"

namespace bd{
    class Cpp:public Module{
    public:
        Cpp(){
            this->_inr = new Datafield(typeid(std::string));
            this->_remark = new Datafield(typeid(std::string));
            this->_number = new Datafield(typeid(int));
            this->addChild();
        }
        ~Cpp(){
            if (this->_inr)
                delete this->_inr;
            if (this->_remark)
                delete this->_remark;
            if (this->_number)
                delete this->_number;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_datafields.insert(std::make_pair(std::string("inr"), this->_inr));
                this->_datafields.insert(std::make_pair(std::string("remark"), this->_remark));
                this->_datafields.insert(std::make_pair(std::string("number"), this->_number));
                this->_childAdded = true;
            }            
        }
    public:
        void set_Inr(const std::string & value){
            this->_inr->setValue(value);
        }
        void set_Remark(const std::string &value){
            this->_remark->setValue(value);
        }
        std::string get_Inr(){
            return boost::any_cast<std::string>(*this->_inr);
        }
        std::string get_Remark(){
            return boost::any_cast<std::string>(*this->_remark);
        }
        int get_Number(){
            return boost::any_cast<int>(*this->_number);
        }
    protected:
        Datafield* _inr;
        Datafield* _remark;
        Datafield* _number;
    };
}
#endif