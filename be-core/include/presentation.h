#ifndef _BE_DESIGNER_PRESENTATION_H_
#define _BE_DESIGNER_PRESENTATION_H_

#include <list>

namespace bd{
	class Object;
	class Attribute;

    class Presentation{
	public:
		Presentation();
		~Presentation();
    public:
		virtual void setModified(Attribute *item);
		virtual std::list<Attribute*> getModifiedList();
		virtual void clear();
	protected:
		std::list<Attribute*> _modifiedList;
    };
}

#endif