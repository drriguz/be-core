#ifndef _TST_CPP_ENTITY_H_
#define _TST_CPP_ENTITY_H_

#include "bd/be-designer.h"
#include <string>
#include <soci.h>
#include <vector>

using namespace tst;
using namespace bd;

namespace tst {
	class CppEntity :public Entity {
	public:
		std::string inr;
		std::string remark;
	public:
		virtual bool save(soci::session &sql);
		virtual bool read(soci::session &sql, const std::string &whereClause);
		virtual std::vector<Entity*>* readSet(soci::session &sql, const std::string &whereClause);
	};
}


namespace soci {
	template<> struct type_conversion<tst::CppEntity> {
		typedef values base_type;

		static void from_base(values const &v, indicator /* ind */, tst::CppEntity &b) {
			b.inr = v.get<std::string>("inr");
			b.remark = v.get<std::string>("remark");
		}

		static void to_base(tst::CppEntity const & b, values & v, indicator & ind) {
			v.set("inr", b.inr);
			v.set("remark", b.remark);
			ind = i_ok;
		}
	};
}


#endif