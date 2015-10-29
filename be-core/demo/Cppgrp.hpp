#ifndef _TST_CPPGRP_H_
#define _TST_CPPGRP_H_

#include "bd/be-designer.h"
#include "Cpp.hpp"
#include "CppList.hpp"
#include "Events.h"

#include <iostream>
using namespace bd;

namespace tst {
    class Cppgrp :public Module{
    public:
        Cppgrp(){
            this->_cpp = new Cpp();
			this->_cpplst = new CppList();
            this->_cppgrp_init_1000 = new Cppgrp_Init_1000(this);
            this->_cppgrp_btn_event_100 = new Cppgrp_btn_event_100(this);
			this->_btn = new Datafield(typeid(std::string).name());
			this->_tmp = new Datafield(typeid(int).name());
            this->addChild();
        }
        ~Cppgrp(){
            if (this->_cpp)
                delete this->_cpp;
			if (this->_cpplst)
				delete this->_cpplst;
			if (this->_btn)
				delete this->_btn;
			if (this->_tmp)
				delete this->_tmp;
            if (this->_cppgrp_init_1000)
                delete this->_cppgrp_init_1000;
            if (this->_cppgrp_btn_event_100)
                delete this->_cppgrp_btn_event_100;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_modules.insert(std::make_pair(std::string("cpp"), this->_cpp)); 
				this->_modules.insert(std::make_pair(std::string("cpplst"), this->_cpplst));
				this->_datafields.insert(std::make_pair(std::string("btn"), this->_btn));
				this->_datafields.insert(std::make_pair(std::string("tmp"), this->_tmp));				
				this->_cpp->addChild();
                this->_childAdded = true;
            }
        }
        virtual void bindRules(Context *context){
            if (!this->_eventBinded){
				context->getRootModule()->addInitRule(this->_cppgrp_init_1000);                
				this->_btn->addEventRule(_cppgrp_btn_event_100);                
				this->_cpp->bindRules(context);	
				this->_cpplst->bindRules(context);
                this->_eventBinded = true;
            }
        }
        Cpp* getCpp(){
            return this->_cpp;
        }
		CppList* getCppList() {
			return this->_cpplst;
		}
		void set_Btn(const std::string &value) {
			this->_btn->setValue(value);
		}
		Datafield* get_Btn() {
			return this->_btn;
		}
		void set_Tmp(int value) {
			this->_tmp->setValue(value);
		}
		Datafield* get_Tmp() {
			return this->_tmp;
		}
    protected:
        Cpp* _cpp;
		CppList* _cpplst;
		Datafield* _btn;
		Datafield* _tmp;
        Cppgrp_Init_1000* _cppgrp_init_1000;
        Cppgrp_btn_event_100* _cppgrp_btn_event_100;
    };
}
#endif