#include "presentation.h"
#include "attribute.h"
using namespace bd;

Presentation::Presentation() {

}

Presentation::~Presentation() {

}

void Presentation::setModified(Attribute *item) {
	item->setAttribute(ATTR_MODIFIED, "true");
	this->_modifiedList.push_back(item);
}
std::list<Attribute*> Presentation::getModifiedList() {
	return this->_modifiedList;
}
void Presentation::clear() {
	this->_modifiedList.clear();
}