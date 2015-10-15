#ifndef _TST_CPPGRP_EVENTS_H_
#define _TST_CPPGRP_EVENTS_H_

#include "be-designer.h"
#include <iostream>
namespace bd{
    class Cppgrp_Init_100 :public Rule{
    public:
        Cppgrp_Init_100(){
            this->_order = 100;
        }
        ~Cppgrp_Init_100(){

        }
    public:
        virtual bool invoke(Context &context){
            std::cout << "Cppgrp/Init/100 invoked!" << std::endl;
            return true;
        }
    };

    class Cppgrp_b1_event_100 :public EventRule{
    public:
        Cppgrp_b1_event_100(){
            this->_type = EventType::ON_CLICK;
            this->_order = 100;
        }
        ~Cppgrp_b1_event_100(){

        }
    public:
        virtual bool invoke(Context &context, Event eventType){
            std::cout << "Cppgrp/b1/onClick/100 invoked!" << std::endl;
            return true;
        }
    };
}
#endif