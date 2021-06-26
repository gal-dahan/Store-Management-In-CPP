#pragma once

#include "MyPoint.h"

class MyShape : public CObject {
public:
	DECLARE_SERIAL(MyShape)
	MyShape();
	//setter's and getter's
	void setBegin(const MyPoint &p);
	void setEnd(const MyPoint &p);
	
	void setBackGroundColor(COLORREF);
	void setBorderColor(COLORREF);
	
	MyPoint getBegin() ;
	MyPoint getEnd() ;

	virtual void drawShape(CPaintDC &dc) {}
	void draw(CPaintDC &dc);
	
	void Serialize(CArchive& archive);

	virtual bool contains(CPoint point) { return false; }
	
protected:
	MyPoint begin, end;
	COLORREF backGroundColor, borderColor;
};