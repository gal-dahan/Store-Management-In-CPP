#pragma once

#include "MyFactory.h"
#include "MyRectangle.h"

class MyRectangleFactory : public MyFactory {
public:
	MyShape* create() { return new MyRectangle(); }
};