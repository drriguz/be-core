#include "bd/presentation.h"
#include "bd/attribute.h"
using namespace bd;

Presentation::Presentation() {

}

Presentation::~Presentation() {

}

void Presentation::setModified(const std::string &url, Attribute *item) {
	item->setAttribute(ATTR_MODIFIED, "true");
	item->setAttribute(ATTR_URL, url);
	this->_modifiedMap[url] = item;
}
std::map<std::string, Attribute*> Presentation::getModifiedList() {
	return this->_modifiedMap;
}
void Presentation::clear() {
	this->_modifiedMap.clear();
}