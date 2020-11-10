#pragma once
#include "graph.h"
class line :
	public graph
{
public:
	line() :line(50, 50, 100, 100) {}
	line(int l, int u, int r, int d);
	void onDraw(CDC* pDC);
	int getGraphID() { return 1; }
	~line();
};