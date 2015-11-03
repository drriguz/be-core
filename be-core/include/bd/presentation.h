#ifndef _BE_DESIGNER_PRESENTATION_H_
#define _BE_DESIGNER_PRESENTATION_H_

#include <map>
#include <string>

namespace bd{
	class Object;
	class Attribute;

    class Presentation{
	public:
		Presentation();
		~Presentation();
    public:
		virtual void setModified(const std::string &url, Attribute *item);
		virtual void error(const std::string &url, const std::string &error, Attribute *item);
		virtual void tip(const std::string &url, const std::string &tip, Attribute *item);
		virtual std::map<std::string, Attribute*> getModifiedList();
		virtual void clear();
	protected:
		std::map<std::string, Attribute*> _modifiedMap;
		std::map<std::string, Attribute*> _errorMap;
    };
}

#endif