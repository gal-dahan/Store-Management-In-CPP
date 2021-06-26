#pragma once

#include "MyShape.h"

class MyEllipse : public MyShape {
	DECLARE_SERIAL(MyEllipse);
	void drawShape(CPaintDC &dc);
	//contains for bonus question - not working at the moment
	bool contains(CPoint point);
};