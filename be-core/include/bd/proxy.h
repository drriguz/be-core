#ifndef _BE_DESIGNER_PROXY_MODULE_H_
#define _BE_DESIGNER_PROXY_MODULE_H_

#include "object.h"
#include "module.h"

namespace bd {
	class ProxyModule :public Module {
	public:
		ProxyModule();
		~ProxyModule();
	public:
		virtual Module* getHost();
		virtual void setHost(Module *module);
	protected:
		Module *_host;
	};
}
#endif