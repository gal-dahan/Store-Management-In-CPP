#pragma once

#include "MyFactory.h"
#include "MySquare.h"

class MySquareFactory : public MyFactory {
public:
	MyShape * create() { return new MySquare(); }
};