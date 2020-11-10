#pragma once
#include "graph.h"
class rectangle :
	public graph
{
public:
	//DECLARE_SERIAL(graph)
	//void Serialize(CArchive& ar);
	rectangle() :graph(50, 50, 100, 100) {}
	rectangle(int l, int u, int r, int d);
	void onDraw(CDC* pDC);
	int getGraphID() { return 2; }
	~rectangle();
};