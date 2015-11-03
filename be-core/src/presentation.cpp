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
void Presentation::error(const std::string &url, const std::string &error, Attribute *item) {
	item->setAttribute(ATTR_ERROR, error);
	item->setAttribute(ATTR_URL, url);
	this->_modifiedMap[url] = item;
}
void Presentation::tip(const std::string &url, const std::string &tip, Attribute *item) {
	item->setAttribute(ATTR_TIP, tip);
	item->setAttribute(ATTR_URL, url);
	this->_modifiedMap[url] = item;
}
std::map<std::string, Attribute*> Presentation::getModifiedList() {
	return this->_modifiedMap;
}
void Presentation::clear() {
	this->_modifiedMap.clear();
}