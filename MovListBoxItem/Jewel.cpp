#include "stdafx.h"
#include "Jewel.h"
#include <time.h> 
Jewel::Jewel(const char* name) :Item(name) {
	
}
Jewel::~Jewel() {

}
double Jewel::get_price() {
	return rand() % 100 ;
}