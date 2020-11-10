#pragma once
#include "graph.h"
class arrow :
	public graph
{
public:
	arrow(int l, int u, int r, int d);
	void onDraw(CDC* pDC);
	int getGraphID() { return 4; }
	~arrow();
};