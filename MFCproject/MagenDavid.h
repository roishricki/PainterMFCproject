#pragma once
#include"Figure.h"


class MagenDavid : public Figure
{
	DECLARE_SERIAL(MagenDavid)

public:
	MagenDavid() :Figure() {}
	MagenDavid(CPoint p1, CPoint p2);
	MagenDavid(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor, int width);
	~MagenDavid();
	virtual void Draw(CDC* dc);
};

