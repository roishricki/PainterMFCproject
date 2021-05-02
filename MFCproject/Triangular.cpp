#include "stdafx.h"
#include "Triangular.h"

IMPLEMENT_SERIAL(Triangular, Figure, 1)

Triangular::Triangular(CPoint p1, CPoint p2) : Figure(p1, p2, RGB(255, 255, 255), RGB(255, 255, 255), 1)
{
}

Triangular::Triangular(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width)
	:Figure(p1,p2,color,framecolor,width)
{
}


void Triangular::Draw(CDC* dc)
{
	CPoint p[3];
	p[0] = P1;
	p[1] = { (P1.x + P2.x) / 2,P2.y };
	p[2] = { P2.x,P1.y };
	dc->Polygon(p, 3);
}
