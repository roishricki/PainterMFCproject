#pragma once
#include"Figure.h"

class Triangular : public Figure
{
	DECLARE_SERIAL(Triangular)

public:
	Triangular() : Figure() {}
	Triangular(CPoint p1, CPoint p2);
	Triangular(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width);
	virtual void  Draw(CDC* dc);
};

