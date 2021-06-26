#pragma once

#include "MyFactory.h"
#include "MyEllipse.h"

class MyEllipseFactory : public MyFactory {
public:
	MyShape* create() { return new MyEllipse(); }
};