#include "stdafx.h"  
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure() :P1(0, 0), P2(0, 0), Color(RGB(255, 255, 255)), FrameClr(RGB(255, 255, 255)),WidthPen(1) {}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << Color;
		ar << FrameClr;
		ar << WidthPen;
	}
	else
	{
		ar >> P1;
		ar >> P2;
		ar >> Color;
		ar >> FrameClr;
		ar >> WidthPen;
	}
}

void Figure::setColor(COLORREF new_Color)
{
	Color = new_Color;
}

void Figure::setFrameColor(COLORREF new_Frame_Color)
{
	FrameClr = new_Frame_Color;
}

void Figure::Draw(CDC* dc)
{
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);

}

Figure& Figure::operator=(const Figure& f)
{
	this->P1 = f.P1;
	this->P2 = f.P2;
	this->Color = f.Color;
	this->FrameClr = f.FrameClr;

	return *this;
}

bool Figure::isInside(const CPoint& P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
void Figure::Shift(int dx, int dy)
{
	P1 += CPoint(dx, dy);
	P2 += CPoint(dx, dy);
}
