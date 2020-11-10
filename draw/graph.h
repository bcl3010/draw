#pragma once
class graph :
	public CObject
{
protected:
	//�߿�
	DECLARE_SERIAL(graph)
	int left, up, right, down;
	//ѡ��״̬
	unsigned int state;
	int sx, sy;
	int  f_width = 5;
	int fcolor = 0xffffff, bcolor = 0;

public:
	graph() :graph(50, 50, 100, 100) {

	}
	graph(int l, int u, int r, int d);
	void Offset(int cx, int cy);
	void  onPress(int x, int y);	//  ��갴��
	int  onMove(int cx, int cy);	//  ����ƶ�
	void  onRelease(int x, int y);	//  ����ͷ�
	virtual void onDraw(CDC* pDC);
	virtual int getGraphID() { return 0; }
	virtual void Serialize(CArchive& ar);
	void SetFillColor(int color);
	void SetBorderColor(int color);
	~graph();
};