#pragma once
#include "graph.h"
class triangle :
	public graph
{
protected:
public:
	triangle(int l, int u, int r, int d);
	int getGraphID() { return 3; }
	void onDraw(CDC* pDC);
	~triangle();
};