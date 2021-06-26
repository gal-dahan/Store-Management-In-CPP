#pragma once
//Abstract class
class Item
{
public:
	Item( const char* name);
	~Item();
	virtual double get_price() =0;
	char* get_name() ;

    void set_name(const char* name);
protected:
	char name[20];
};

