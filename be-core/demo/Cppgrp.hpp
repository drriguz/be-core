#ifndef _TST_CPPGRP_H_
#define _TST_CPPGRP_H_

#include "be-designer.h"
#include "Cpp.hpp"
#include "Cppgrp_events.h"

#include <iostream>

namespace bd{
    class Cppgrp :public Module{
    public:
        Cppgrp(){
            this->_cpp = new Cpp();
            this->_cppgrp_init_100 = new Cppgrp_Init_100();
            this->_cppgrp_b1_event_100 = new Cppgrp_b1_event_100();
            this->addChild();
        }
        ~Cppgrp(){
            if (this->_cpp)
                delete this->_cpp;
            if (this->_cppgrp_init_100)
                delete this->_cppgrp_init_100;
            if (this->_cppgrp_b1_event_100)
                delete this->_cppgrp_b1_event_100;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_modules.insert(std::make_pair(std::string("cpp"), this->_cpp));      
                this->_childAdded = true;
            }
        }
        virtual void bindRules(){
            if (!this->_eventBinded){
                this->_rules.push_back(this->_cppgrp_init_100);
                this->_eventRules.push_back(this->_cppgrp_b1_event_100);
                this->_eventBinded = true;
            }
        }
        virtual bool init(Context &context){
            return this->_cppgrp_init_100->invoke(context);
        }
        Cpp* getCpp(){
            return this->_cpp;
        }
    protected:
        Cpp* _cpp;
        Cppgrp_Init_100* _cppgrp_init_100;
        Cppgrp_b1_event_100* _cppgrp_b1_event_100;
    };
}
#endif