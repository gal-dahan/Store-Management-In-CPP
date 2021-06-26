#pragma once

#include "MyShape.h"

class MyRectangle : public MyShape
{
	DECLARE_SERIAL(MyRectangle)
	void drawShape(CPaintDC &dc);
	bool contains(CPoint point);
};