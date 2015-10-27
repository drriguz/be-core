#ifndef _TST_CPP_H_
#define _TST_CPP_H_

#include <string>
#include <soci.h>
#include <vector>

#include "bd/be-designer.h"
using namespace bd;

namespace tst {
    class CppEntity:public Entity{
	public:
        std::string inr;
        std::string remark;
	public:
		virtual bool save(soci::session &sql) {
			sql << "insert into cpp(inr, remark) values(:INR, :REMARK)"
				, soci::use(inr)
				, soci::use(remark);
			return true;
		}

		virtual bool read(soci::session &sql, const std::string &whereClause) {
			sql << "select * from cpp " + whereClause, soci::into(*this);
			return true;
		}

		virtual std::vector<Entity*>* readSet(soci::session &sql, const std::string &whereClause) {
			std::vector<std::string> vInr(1000);
			std::vector<std::string> vRemark(1000);
			sql << "select inr,remark from cpp " + whereClause, soci::into(vInr), soci::into(vRemark);
			std::vector<Entity*> *list = new std::vector<Entity*>(vInr.size());
			for (int i = 0; i < vInr.size(); i++) {
				CppEntity* item = new CppEntity();
				item->inr = vInr.at(i);
				item->remark = vInr.at(i);
				list->push_back(item);				
			}
			return list;
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