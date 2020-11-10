#include "framework.h"


arrow::arrow(int l, int u, int r, int d) :graph(l, u, r, d)
{
}

void arrow::onDraw(CDC* pDC)
{
	CPoint pts[2], pt[3];
	pts[0].x = left;
	pts[0].y = (up + down) / 2;
	pts[1].x = (left + right) / 2;
	pts[1].y = (up + down) / 2;
	pt[0].x = (left + right) / 2;
	pt[0].y = up;
	pt[1].x = (left + right) / 2;
	pt[1].y = down;
	pt[2].x = right;
	pt[2].y = (up + down) / 2;
	CBrush b(fcolor);
	pDC->SelectObject(&b);
	CPen p(PS_SOLID, 1, bcolor);
	pDC->SelectObject(&p);
	pDC->Polygon(pts, 2);
	pDC->Polygon(pt, 3);
}
arrow::~arrow()
{
}