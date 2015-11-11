#ifndef _TST_CPPGRP_H_
#define _TST_CPPGRP_H_

#include "bd/be-designer.h"
#include "Cpp.h"

#include <iostream>
using namespace bd;

namespace tst {
	class CppList;
	class Cppgrp;

	class Cppgrp_Init_1000 :public Rule {
	public:
		Cppgrp_Init_1000(Cppgrp* parent);
		~Cppgrp_Init_1000();
	public:
		virtual bool invoke(Context &context);
	};

	class Cppgrp_btn_event_100 :public EventRule {
	public:
		Cppgrp_btn_event_100(Cppgrp* parent);
		~Cppgrp_btn_event_100();
	public:
		virtual bool invoke(Context &context, Event eventType);
	};

    class Cppgrp :public Module{
    public:
		Cppgrp();
		~Cppgrp();
    public:
		virtual void addChild();
		virtual void bindRules(Context *context);
		Cpp* getCpp();
		CppList* getCppList();
		void set_Btn(const std::string &value);
		Datafield* get_Btn();
		void set_Tmp(int value);
		Datafield* get_Tmp();
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