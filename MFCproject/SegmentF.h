#pragma once
#include"Figure.h"

class SegmentF : public Figure
{
	DECLARE_SERIAL(SegmentF)

public:
	SegmentF() : Figure() {}
	SegmentF(CPoint p1, CPoint p2);
	SegmentF(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width);
	virtual void  Draw(CDC* dc);
};

