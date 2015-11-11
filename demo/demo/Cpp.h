#ifndef _TST_CPP_HPP_H_
#define _TST_CPP_HPP_H_

#include "bd/be-designer.h"
#include <string>
#include <soci.h>
#include <vector>

using namespace bd;

namespace tst {
	class CppEntity;

	class Cpp :public Module, public PersistenceAble {
	public:
		Cpp();
		Cpp(const Cpp& cpp);
		~Cpp();
	public:
		virtual void addChild();
		virtual void bindRules(Context *context);
		virtual Entity* createObject();
		virtual bool fromObject(Entity* entity);
		virtual Entity* read(soci::session &sql, const std::string &whereClause);
		virtual std::vector<Entity*>* readSet(soci::session &sql, const std::string &whereClause);
	public:
		void set_Inr(const std::string & value);
		void set_Remark(const std::string &value);
		void set_Number(int value);
		Datafield* get_Inr();
		Datafield* get_Remark();
		Datafield* get_Number();
	protected:
		Datafield* _inr;
		Datafield* _remark;
		Datafield* _number;
		CppEntity* _entity;
	};
}


#endif