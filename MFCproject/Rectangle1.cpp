#include "stdafx.h" // must be 1st
#include "Rectangle1.h"

IMPLEMENT_SERIAL(Rectangle1, Figure, 1)

Rectangle1::Rectangle1() :Figure() {}

Rectangle1::Rectangle1(CPoint p1, CPoint p2) : Figure(p1, p2, RGB(255, 255, 255), RGB(255, 255, 255),1)
{
}

Rectangle1::Rectangle1(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor,int width)
	: Figure(p1, p2, color, framecolor,width)
{
}

void Rectangle1::Draw(CDC* dc)
{
	(*dc).Rectangle(P1.x,P1.y, P2.x,P2.y);
}
