#pragma once
#include "Figure.h"
class Rectangle1 : public Figure {

	DECLARE_SERIAL(Rectangle1)

public:

	Rectangle1();
	Rectangle1(CPoint p1, CPoint p2);
	Rectangle1(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width);
	virtual void Draw(CDC* dc);

};
