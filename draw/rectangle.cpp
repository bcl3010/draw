#include "framework.h"

rectangle::rectangle(int l, int u, int r, int d) :graph(l, u, r, d)
{
	state = 0;
	fcolor = 0xffffff;

}

void rectangle::onDraw(CDC* pDC)
{
	CBrush b(fcolor);
	pDC->SelectObject(&b);
	CRect r(left, up, right, down);
	pDC->FillRect(&r, &b);
	CPen p(PS_SOLID, 1, bcolor);
	pDC->SelectObject(&p);
	pDC->Rectangle(left, up, right, down);
	pDC->MoveTo(left, up);
}

rectangle::~rectangle()
{
}