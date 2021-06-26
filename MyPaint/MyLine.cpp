#include "stdafx.h"
#include "MyLine.h"

IMPLEMENT_SERIAL(MyLine, MyShape, 1)

void MyLine::drawShape(CPaintDC &dc) {
	dc.MoveTo(begin.getX(), begin.getY());
	dc.LineTo(end.getX(), end.getY());
}