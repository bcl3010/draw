#include "framework.h"
triangle::triangle(int l, int u, int r, int d) :graph(l, u, r, d)
{
	state = 0;
	fcolor = 0xffffff;
}

void triangle::onDraw(CDC* pDC)
{
	CPoint pts[3];
	pts[0].x = (left + right) / 2;
	pts[0].y = up;
	pts[1].x = left;
	pts[1].y = down;
	pts[2].x = right;
	pts[2].y = down;
	CBrush b(fcolor);
	pDC->SelectObject(&b);
	CPen p(PS_SOLID, 1, bcolor);
	pDC->SelectObject(&p);
	pDC->Polygon(pts, 3);
}

triangle::~triangle()
{
}