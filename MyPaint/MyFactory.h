#pragma once

#include "MyShape.h"

class MyFactory {
public:
	virtual MyShape* create() = 0;
};