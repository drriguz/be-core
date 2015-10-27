#ifndef _TST_CPP_HPP_H_
#define _TST_CPP_HPP_H_

#include "bd/be-designer.h"
#include "Entity.h"

using namespace bd;
namespace tst{
    class Cpp:public Module, public PersistenceAble{
    public:
        Cpp(){
            this->_inr = new Datafield(typeid(std::string));
            this->_remark = new Datafield(typeid(std::string));
            this->_number = new Datafield(typeid(int));            
        }
        ~Cpp(){
            if (this->_inr)
                delete this->_inr;
            if (this->_remark)
                delete this->_remark;
            if (this->_number)
                delete this->_number;
			if (this->_entity)
				delete this->_entity;
        }
    public:
        virtual void addChild(){
            if (!this->_childAdded){
                this->_datafields.insert(std::make_pair(std::string("inr"), this->_inr));
                this->_datafields.insert(std::make_pair(std::string("remark"), this->_remark));
                this->_datafields.insert(std::make_pair(std::string("number"), this->_number));
                this->_childAdded = true;
            }            
        }
		virtual void bindRules(Context *context) {

		}
		virtual Entity* createObject() {
			CppEntity *entity = new CppEntity();
			entity->inr = ModuleUtils::getValue(*this->_inr);
			entity->remark = ModuleUtils::getValue(*this->_remark);
			return entity;
		}
		virtual bool fromObject(Entity* entity) {
			CppEntity *cppEntity = (CppEntity*)entity;			
			this->set_Inr(cppEntity->inr);
			this->set_Remark(cppEntity->remark);
			return true;
		}
		virtual Entity* read(soci::session &sql, const std::string &whereClause) {
			CppEntity *entity = new CppEntity();
			entity->read(sql, whereClause);
			return entity;
		}
    public:
        void set_Inr(const std::string & value){
            this->_inr->setValue(value);
        }
        void set_Remark(const std::string &value){
            this->_remark->setValue(value);
        }
		void set_Number(int value) {
			this->_number->setValue(value);
		}

		Datafield* get_Inr(){
            return this->_inr;
        }
		Datafield* get_Remark(){
            return this->_remark;
        }
		Datafield* get_Number(){
            return this->_number;
        }
		
    protected:
        Datafield* _inr;
        Datafield* _remark;
        Datafield* _number;
		CppEntity* _entity;
    };
}
#endif