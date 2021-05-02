#pragma once
#include "stdafx.h"
class Figure : public CObject {
	DECLARE_SERIAL(Figure)
	CPoint P1;
	CPoint P2;
protected:
	COLORREF Color;
	COLORREF FrameClr;
	int WidthPen;
public:

	Figure();
	Figure(CPoint p1, CPoint p2, COLORREF color, COLORREF frameclr,int width)
		:P1(p1), P2(p2), Color(color),FrameClr(frameclr),WidthPen(width) {}
	~Figure() {}
	void Serialize(CArchive& ar);
	void setColor(COLORREF new_Color);
	void setFrameColor(COLORREF new_Frame_Color);
	void setWidthPen(int width) { WidthPen = width; }
	int getWidthPen() { return WidthPen; }
	COLORREF getColor() { return Color; }
	COLORREF getFrameColor() { return FrameClr; }
	virtual void Draw(CDC* dc) ;
	CPoint getP1() const { return P1; }
	CPoint getP2() const { return P2; }
	Figure& operator=(const Figure&);

	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint& P) const;
	virtual void Shift(int dx, int dy);
};
