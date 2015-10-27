#ifndef _TST_CPP_H_
#define _TST_CPP_H_

#include <string>
#include <soci.h>
#include "bd/be-designer.h"
using namespace bd;

namespace tst {
    class CppEntity:public Entity{
	public:
        std::string inr;
        std::string remark;
	public:
		bool save(soci::session &sql) {
			sql << "insert into cpp(inr, remark) values(:INR, :REMARK)"
				, soci::use(inr)
				, soci::use(remark);
			return true;
		}

		bool read(soci::session &sql, const std::string &whereClause) {
			sql << "select * from cpp " + whereClause, soci::into(*this);
			return true;
		}
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