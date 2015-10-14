#ifndef _BE_DESIGNER_ATTRIBUTE_H_
#define _BE_DESIGNER_ATTRIBUTE_H_

#include <map>
#include <string>

namespace bd{
    class Attribute{
    public:
        Attribute();
        ~Attribute();
    public:
        std::string getAttribute(const std::string &attrName) const;
        void setAttribute(const std::string &attrName, const std::string &value);
    protected:
        std::map<const std::string, std::string> _attrMap;
    };
}

#endif