#ifndef _TST_SYSMOD_H
#define _TST_SYSMOD_H
#include "bd/be-designer.h"


using namespace bd;
namespace tst {
	class Sysmod;
	class Cppgrp;

	class Sysmod_Init_10 :public Rule {
	public:
		Sysmod_Init_10(Sysmod *parent);
		~Sysmod_Init_10();
	public:
		virtual bool invoke(Context &context);
	};

	class Sysmod :public Module{
	public:
		Sysmod();
		~Sysmod();
	public:
		virtual void addChild();
		virtual void bindRules(Context *context);
	public:
		void set_User(const std::string & value);
		void set_Bch(const std::string &value);
		void set_Token(const std::string &value);

		Datafield* get_User();
		Datafield* get_Bch();
		Datafield* get_Token();

		Cppgrp* getRecgrp();
		void setRecgrp(Cppgrp* recgrp);
	protected:
		Datafield* _user;
		Datafield* _bch;
		Datafield* _token;
		ProxyModule* _recgrp;
		Sysmod_Init_10* _sysmod_Init_10;
	};

}

#endif
