#ifndef _BE_DESIGNER_EXTEND_API_H_
#define _BE_DESIGNER_EXTEND_API_H_

#include <string>

namespace bd {
	class UiSupport {
		virtual int messageBox(const std::string &title, const std::string &msg) = 0;
		virtual int promote(const std::string &title, const std::string &msg) = 0;
		virtual int popup(const std::string &panel) = 0;
	};
}
#endif