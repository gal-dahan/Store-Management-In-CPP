#pragma once

#include "MyShape.h"

class MyTriangle : public MyShape {
	DECLARE_SERIAL(MyTriangle)
	void drawShape(CPaintDC &dc);
public:
	MyPoint midPoint;
};