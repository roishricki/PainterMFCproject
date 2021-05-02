//!! 15 b
#include "stdafx.h"
#include "EllipseF.h"

//!! 22 b
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
//!! 22 e

EllipseF::EllipseF(CPoint p1, CPoint p2,COLORREF color,COLORREF framecolor,int width)
	:Figure(p1, p2,color,framecolor,width)
{
}
EllipseF::~EllipseF()
{
}
void EllipseF::Draw(CDC* dc) 
{	
	(*dc).Ellipse(P1.x, P1.y, P2.x, P2.y);
}
//!! 15 e
