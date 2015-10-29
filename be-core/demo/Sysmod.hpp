#ifndef _TST_SYSMOD_H
#define _TST_SYSMOD_H
#include "bd/be-designer.h"
#include "Entity.h"

using namespace bd;
namespace tst {
	class Sysmod :public Module{
	public:
		Sysmod() {
			this->_user = new Datafield(typeid(std::string).name());
			this->_bch = new Datafield(typeid(std::string).name());
			this->_token = new Datafield(typeid(std::string).name());
			this->_sysmod_Init_10 = new Sysmod_Init_10(this);
		}
		Sysmod(const Sysmod& sysmod) {
			this->_user = new Datafield(*sysmod._user);
			this->_bch = new Datafield(*sysmod._bch);
			this->_token = new Datafield(*sysmod._token);
			this->_sysmod_Init_10 = new Sysmod_Init_10(this);
		}
		~Sysmod() {
			if (this->_user)
				delete this->_user;
			if (this->_bch)
				delete this->_bch;
			if (this->_token)
				delete this->_token;
			if (this->_sysmod_Init_10)
				delete this->_sysmod_Init_10;
		}
	public:
		virtual void addChild() {
			if (!this->_childAdded) {
				this->_datafields.insert(std::make_pair(std::string("user"), this->_user));
				this->_datafields.insert(std::make_pair(std::string("bch"), this->_bch));
				this->_datafields.insert(std::make_pair(std::string("token"), this->_token));
				this->_childAdded = true;
			}
		}
		virtual void bindRules(Context *context) {
			if (!this->_eventBinded) {
				context->getRootModule()->addInitRule(this->_sysmod_Init_10);
				this->_eventBinded = true;
			}
		}
	public:
		void set_User(const std::string & value) {
			this->_user->setValue(value);
		}
		void set_Bch(const std::string &value) {
			this->_bch->setValue(value);
		}
		void set_Token(const std::string &value) {
			this->_token->setValue(value);
		}

		Datafield* get_User() {
			return this->_user;
		}
		Datafield* get_Bch() {
			return this->_bch;
		}
		Datafield* get_Token() {
			return this->_token;
		}

	protected:
		Datafield* _user;
		Datafield* _bch;
		Datafield* _token;
		Sysmod_Init_10* _sysmod_Init_10;
	};
}

#endif
