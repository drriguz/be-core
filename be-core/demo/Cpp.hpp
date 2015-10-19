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
		virtual void bindRules(Context *context) {

		}
    public:
        void set_Inr(const std::string & value){
            this->_inr->setValue(value);
        }
        void set_Remark(const std::string &value){
            this->_remark->setValue(value);
        }
		void set_Number(int value) {
			this->_number->setValue(value);
		}

		Datafield* get_Inr(){
            return this->_inr;
        }
		Datafield* get_Remark(){
            return this->_remark;
        }
		Datafield* get_Number(){
            return this->_number;
        }
    protected:
        Datafield* _inr;
        Datafield* _remark;
        Datafield* _number;
    };
}
#endif