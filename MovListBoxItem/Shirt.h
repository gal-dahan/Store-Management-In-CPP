#pragma once
#include "Clothes.h"
class Shirt :
    public Clothes
{
public:
    Shirt(const char* name, char size);
     ~Shirt();
     double get_price();

};
