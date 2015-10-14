#ifndef _TST_CPP_HPP_H_
#define _TST_CPP_HPP_H_

#include "module.h"
#include "datafield.h"

namespace bd{
    class Cpp:public Module{
    public:
        Cpp(){
            this->_inr = new Datafield(typeid(std::string));
            this->_remark = new Datafield(typeid(std::string));
        }
        ~Cpp(){
            if (this->_inr)
                delete this->_inr;
            if (this->_remark)
                delete this->_remark;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_datafields.insert(std::make_pair(std::string("inr"), this->_inr));
                this->_datafields.insert(std::make_pair(std::string("remark"), this->_remark));
                this->_childAdded = true;
            }            
        }
    public:
        void set_Inr(const std::string & inr){
            this->_inr->setValue(boost::any(inr));
        }
        void set_Remark(const std::string &remark){
            this->_remark->setValue(boost::any(remark));
        }
        std::string get_Inr(){
            return boost::any_cast<std::string>(*this->_inr);
        }
        std::string get_Remark(){
            return boost::any_cast<std::string>(*this->_remark);
        }
    protected:
        Datafield* _inr;
        Datafield* _remark;
    };
}
#endif