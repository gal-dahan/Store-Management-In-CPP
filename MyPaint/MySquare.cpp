#include "stdafx.h"
#include "MySquare.h"

IMPLEMENT_SERIAL(MySquare, MyRectangle, 1)

void MySquare::drawShape(CPaintDC &dc) {
	
	int xDist = begin.getX() - end.getX();
	int yDist = begin.getY() - end.getY();
	if (xDist*xDist  >  yDist*yDist)
		dc.Rectangle(begin.getX(), begin.getY(), begin.getX() - xDist, begin.getY() - xDist);
	else
		dc.Rectangle(begin.getX(), begin.getY(), begin.getX() - yDist, begin.getY() - yDist);
	
}