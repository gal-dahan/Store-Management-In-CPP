#include "stdafx.h"
#include "MyShape.h"

IMPLEMENT_SERIAL(MyShape, CObject, 1)

MyShape::MyShape() {}
void MyShape::setBegin(const MyPoint &p) { begin = p; }
void MyShape::setEnd(const MyPoint &p) { end = p; }

MyPoint MyShape::getBegin() { return begin; }
MyPoint MyShape::getEnd() { return end; }

void MyShape::setBackGroundColor(COLORREF chosenColor) { backGroundColor = chosenColor; }
void MyShape::setBorderColor(COLORREF chosenColor) { borderColor = chosenColor; }

void MyShape::draw(CPaintDC &dc) {
	CPen pen(PS_SOLID, 2, borderColor);
	CBrush brush(backGroundColor);
	CPen *oldPen = dc.SelectObject(&pen);
	CBrush *oldBrush = dc.SelectObject(&brush);
	drawShape(dc);
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
}

void MyShape::Serialize(CArchive& archive) {
	if (archive.IsStoring())
	{
		archive << backGroundColor << borderColor << begin.getX() << begin.getY()
			<< end.getX() << end.getY();
	}
	else
	{
		int bx, by, ex, ey;
		archive >> backGroundColor >> borderColor >> bx >> by >> ex >> ey;
		begin.setX(bx);
		begin.setY(by);
		end.setX(ex);
		end.setY(ey);
	}
}