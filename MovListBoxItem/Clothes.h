#pragma once
#include "Item.h"
class Clothes :
    public Item
{
public:
    Clothes(const char* name);
    ~Clothes();
     void set_size(char size);
     int get_size();
protected:
    int size;
    
};

