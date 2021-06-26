#include "stdafx.h"
#include "Pants.h"
Pants::Pants(const char* name, char size) :Clothes(name) {
	this->set_size(size);

}
Pants::~Pants() {

}
double Pants::get_price() {

	if (this->size == 'S')
	{
		return 70;
	}
	else if (this->size == 'M')
	{
		return 80;
	}
	else if (this->size == 'L')
	{
		return 100;
	}
}