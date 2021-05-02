#pragma once
#include "Rectangle1.h"

class Square : public Rectangle1
{
	DECLARE_SERIAL(Square)

public:
	Square() :Rectangle1() {}
	Square(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width);
	~Square() {}
	virtual void Draw(CDC* dc);

};

