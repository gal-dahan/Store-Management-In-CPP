#pragma once
#include "Clothes.h"
class Pants :
    public Clothes
{
public:
    Pants(const char* name, char size);
    ~Pants();
    double get_price();

};

