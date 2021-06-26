#pragma once
#include "Item.h"
class Jewel :
    public Item
{
public:
    Jewel(const char* name);
    ~Jewel();
    double get_price();
};

