#ifndef _TST_CPPTST_HPP_
#define _TST_CPPTST_HPP_

#include "bd/be-designer.h"
#include "Cppgrp.hpp"
#include "Events.h"
#include "Sysmod.hpp"
using namespace bd;

namespace tst {
    class Cpptst :public Transaction{
    public:
        Cpptst(Context* context):Transaction(){
            this->_cppgrp = new Cppgrp();
			this->_cpptst_init_10 = new Cpptst_Init_10(this);
			this->_cppgrp_btn_event_500 = new Cpptst_btn_event_500(this);

			Module* sysmod = context->getSession()->getStaticModule("sysmod");
			if (sysmod)
				this->_sysmod = (Sysmod*)sysmod;
			else {
				this->_sysmod = new Sysmod();
				context->getSession()->setStaticModule("sysmod", this->_sysmod);
			}
        }
		~Cpptst() {
			if (this->_cppgrp)
				delete this->_cppgrp;
			if (this->_cpptst_init_10)
				delete this->_cpptst_init_10;
			if (this->_cppgrp_btn_event_500)
				delete this->_cppgrp_btn_event_500;
		}
    public:
        virtual void addChild(){
            if (!this->_childAdded){               
                this->_modules.insert(std::make_pair(std::string("cppgrp"), this->_cppgrp));
				this->_cppgrp->addChild();
				this->_sysmod->addChild();
                this->_childAdded = true;
            }
        }
		virtual void bindRules(Context *context) {
			if (!this->_eventBinded) {
				context->getRootModule()->addInitRule(this->_cpptst_init_10);
				this->getCppgrp()->get_Btn()->addEventRule(this->_cppgrp_btn_event_500);
				this->_cppgrp->bindRules(context);
				this->_sysmod->bindRules(context);
				this->_eventBinded = true;
			}
		}
        Cppgrp* getCppgrp(){
            return this->_cppgrp;
        }
    protected:
		Sysmod* _sysmod;
        Cppgrp* _cppgrp;
		Cpptst_Init_10* _cpptst_init_10;
		Cpptst_btn_event_500* _cppgrp_btn_event_500;
    };
}
#endif