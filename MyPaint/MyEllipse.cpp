#include "stdafx.h"
#include "MyEllipse.h"
#include <cmath> //for contains pow func'

IMPLEMENT_SERIAL(MyEllipse, MyShape, 1)

void MyEllipse::drawShape(CPaintDC &dc) {
	dc.Ellipse(begin.getX(), begin.getY(), end.getX(), end.getY());
}

bool MyEllipse::contains(CPoint point) {
	MyPoint center;
	double radiusX, result, radiusY;
	//Calculte the radius
	radiusX = (end.getX() - begin.getX()) / 2;
	radiusY = (begin.getY() - end.getY()) / 2;

	center.setX(begin.getX() + radiusX);
	center.setY(end.getY() + radiusY);

	//mathematical calc'
	result = (pow((point.x - center.getX()), 2.0) /
		pow(radiusX, 2)) + (pow(point.y - center.getY(), 2.0) /
			pow(radiusY, 2));
	return (result <= 1.0);
}