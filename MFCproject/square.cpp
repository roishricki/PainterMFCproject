#include "stdafx.h"
#include"Square.h"
#include<math.h>

IMPLEMENT_SERIAL(Square, Rectangle1, 1)

Square::Square(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width) 
	:Rectangle1(p1, p2, color, framecolor, width)
{
}

void Square::Draw(CDC* dc)
{
	int dist = abs(P1.y - P2.y);
	CPoint p1 = { ((P1.x + P2.x) / 2) - (dist / 2),P1.y };
	CPoint p2 = { ((P1.x + P2.x) / 2) + (dist / 2),P2.y };

	(*dc).Rectangle(p1.x, p1.y, p2.x, p2.y);
}
