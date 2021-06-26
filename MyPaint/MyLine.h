#pragma once

#include "MyShape.h"

class MyLine : public MyShape {
	DECLARE_SERIAL(MyLine)
	void drawShape(CPaintDC &dc);
};