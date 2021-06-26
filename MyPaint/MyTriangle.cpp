#include "stdafx.h"
#include "MyTriangle.h"

IMPLEMENT_SERIAL(MyTriangle, MyShape, 1)

void MyTriangle::drawShape(CPaintDC &dc) {
	
	midPoint.setY(end.getY());
	midPoint.setX(begin.getX() - (end.getX() - begin.getX()));
	//adapting values from MyPoint to CPoint
	CPoint b, middle, e;
	middle.y = midPoint.getY();
	middle.x = midPoint.getX();
	b.x = begin.getX();
	b.y = begin.getY();
	e.x = end.getX();
	e.y = end.getY();
	CPoint p_arr[3] = { b,middle,e };
	dc.Polygon(p_arr, 3);
}