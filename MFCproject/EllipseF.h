#pragma once
//!! 15 b
#include "Figure.h"
class EllipseF :public Figure {
	//!! 21 b
	DECLARE_SERIAL(EllipseF)   //!!! NO ";"  
	//!! 21 e
public:
	//!! 22 b
	// must 4 serialization
	EllipseF():Figure() {}
	EllipseF(CPoint p1, CPoint p2, COLORREF color, COLORREF framecolor,int width);
	~EllipseF();
	virtual void Draw(CDC* dc) ;
};
//!! 15 e
