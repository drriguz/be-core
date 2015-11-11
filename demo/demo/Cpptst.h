#ifndef _TST_CPPTST_HPP_
#define _TST_CPPTST_HPP_

#include "bd/be-designer.h"

using namespace bd;

namespace tst {
	class Cppgrp;
	class Sysmod;

	class Cpptst;

	class Cpptst_Init_10 :public Rule {
	public:
		Cpptst_Init_10(Cpptst *parent);
		~Cpptst_Init_10();
	public:
		virtual bool invoke(Context &context);
	};

	class Cpptst_btn_event_500 :public EventRule {
	public:
		Cpptst_btn_event_500(Cpptst *parent);
		~Cpptst_btn_event_500();
	public:
		virtual bool invoke(Context &context, Event eventType);
	};

    class Cpptst :public Transaction{
    public:
		Cpptst(Context* context);
		~Cpptst();
    public:
		virtual void addChild();
		virtual void bindRules(Context *context);
		Cppgrp* getCppgrp();
    protected:
		Sysmod* _sysmod;
        Cppgrp* _cppgrp;
		Cpptst_Init_10* _cpptst_init_10;
		Cpptst_btn_event_500* _cppgrp_btn_event_500;
    };

	
}
#endif