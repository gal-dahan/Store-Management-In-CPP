#include "stdafx.h"
#include "Item.h"
#include "string.h"
//Abstract class
Item::Item(const char* name) {
	this->set_name(name);
}
void Item::set_name(const char* name) {
	strcpy(this->name, name);
}
Item::~Item() {

}
char* Item::get_name() {
	return name;
}