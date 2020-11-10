// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// drawView.cpp: CdrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw.h"
#endif

#include "drawDoc.h"
#include "drawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawView

IMPLEMENT_DYNCREATE(CdrawView, CView)

BEGIN_MESSAGE_MAP(CdrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdrawView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ECTANGLE, &CdrawView::OnRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CdrawView 构造/析构

CdrawView::CdrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CdrawView::~CdrawView()
{
}

BOOL CdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawView 绘图

void CdrawView::OnDraw(CDC* pDC)
{
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	std::list<graph*>::iterator v;
	for (v = pDoc->graphList.begin(); v != pDoc->graphList.end(); ++v) {
		(*v)->onDraw(pDC);
	}

}


// CdrawView 打印


void CdrawView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CdrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CdrawView 诊断

#ifdef _DEBUG
void CdrawView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawDoc* CdrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawDoc)));
	return (CdrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawView 消息处理程序


void CdrawView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->graphList.push_front(new rectangle(50, 50, 100, 100));

	Invalidate();

}


void CdrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	std::list<graph*>::iterator v;
	for (v = pDoc->graphList.begin(); v != pDoc->graphList.end(); ++v) {
		(*v)->onPress(point.x, point.y);
	}
	Invalidate();
	//CView::OnLButtonDown(nFlags, point);

}


void CdrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	std::list<graph*>::iterator v;
	for (v = pDoc->graphList.begin(); v != pDoc->graphList.end(); ++v) {
		(*v)->onRelease(point.x, point.y);
	}
	Invalidate();
	//CView::OnLButtonUp(nFlags, point);

}


void CdrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	std::list<graph*>::iterator v;
	for (v = pDoc->graphList.begin(); v != pDoc->graphList.end(); ++v) {
		(*v)->onMove(point.x, point.y);
	}
	Invalidate();
	//CView::OnMouseMove(nFlags, point);

}
