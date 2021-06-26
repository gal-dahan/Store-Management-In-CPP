#pragma once

#include "MyRectangle.h"

class MySquare : public MyRectangle {
	DECLARE_SERIAL(MySquare)
	void drawShape(CPaintDC &dc);
};