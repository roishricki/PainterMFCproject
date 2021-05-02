#include "stdafx.h"
#include "SegmentF.h"

IMPLEMENT_SERIAL(SegmentF, Figure, 1)

SegmentF::SegmentF(CPoint p1, CPoint p2): Figure(p1, p2, RGB(255, 255, 255), RGB(255, 255, 255), 1)
{
}

SegmentF::SegmentF(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width)
	:Figure(p1, p2, color, framecolor, width)
{
}

void SegmentF::Draw(CDC* dc)
{
	CPoint p1 = this->getP1();
	CPoint p2 = this->getP2();
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);
}
