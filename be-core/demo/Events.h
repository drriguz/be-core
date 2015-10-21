#ifndef _TST_EVENTS_H_
#define _TST_EVENTS_H_

#include "bd/be-designer.h"
#include <iostream>

namespace bd {
	class Cppgrp;
	class Cpptst;
	class Cpp;
}

namespace bd{
    class Cppgrp_Init_1000 :public Rule{
    public:
		Cppgrp_Init_1000(Cppgrp* parent);
		~Cppgrp_Init_1000();
    public:
		virtual bool invoke(Context &context);
    };

    class Cppgrp_btn_event_100 :public EventRule{
    public:
		Cppgrp_btn_event_100(Cppgrp* parent);
		~Cppgrp_btn_event_100();
    public:
		virtual bool invoke(Context &context, Event eventType);
    };
	//
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
}
#endif