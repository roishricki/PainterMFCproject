#include "stdafx.h"
#include "MagenDavid.h"
#include <math.h>

IMPLEMENT_SERIAL(MagenDavid, Figure, 1)


MagenDavid::MagenDavid(CPoint p1, CPoint p2) 
	:Figure(p1, p2, RGB(255, 255, 255), RGB(255, 255, 255), 1)
{
}

MagenDavid::MagenDavid(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width)
	: Figure(p1, p2, color, framecolor, width)
{
}

MagenDavid::~MagenDavid()
{
}

void MagenDavid::Draw(CDC* dc)
{
	CPoint p[3];
	CPoint q[3];
	int dist = sqrt(pow(P1.y - P2.y, 2));
	if (P1.y < P2.y) {
		p[0] = P1;
		p[1] = { (P1.x + P2.x) / 2,P2.y };
		p[2] = { P2.x,P1.y };

		q[0] = { P1.x,P1.y + ((2 * dist) / 3) };
		q[1] = { P2.x,P1.y + ((2 * dist) / 3) };
		q[2] = { p[1].x,P1.y - (dist / 3) };
		(*dc).Polygon(p, 3);
		(*dc).Polygon(q, 3);
	}
	else {
		p[0] = P1;
		p[1] = { (P1.x + P2.x) / 2,P2.y };
		p[2] = { P2.x,P1.y };

		q[0] = { p[1].x ,P1.y + (dist / 3) };
		q[1] = { P1.x ,P2.y + (dist / 3) };
		q[2] = { P2.x ,P2.y + (dist / 3) };
		(*dc).Polygon(p, 3);
		(*dc).Polygon(q, 3);
	}
}
