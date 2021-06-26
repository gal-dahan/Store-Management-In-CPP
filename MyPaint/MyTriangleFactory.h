#pragma once

#include "MyFactory.h"
#include "MyTriangle.h"

class MyTriangleFactory : public MyFactory {
public:
	MyShape * create() { return new MyTriangle(); }
};