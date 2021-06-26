#include "stdafx.h"
#include "Shirt.h"
Shirt::Shirt(const char* name, char size):Clothes(name) {
	this->set_size(size);

}
Shirt::~Shirt() {

}
double Shirt::get_price() {
	
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