
// Dialog1.0View.cpp: CDialog10View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Dialog1.0.h"
#endif

#include "Dialog1.0Doc.h"
#include "Dialog1.0View.h"
#include "Config.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialog10View

IMPLEMENT_DYNCREATE(CDialog10View, CView)

BEGIN_MESSAGE_MAP(CDialog10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDialog10View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW_DIALOG, &CDialog10View::OnShowDialog)
END_MESSAGE_MAP()

// CDialog10View 构造/析构

CDialog10View::CDialog10View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDialog10View::~CDialog10View()
{
}

BOOL CDialog10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDialog10View 绘图

void CDialog10View::OnDraw(CDC* /*pDC*/)
{
	CDialog10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDialog10View 打印


void CDialog10View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDialog10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDialog10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDialog10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDialog10View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDialog10View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDialog10View 诊断

#ifdef _DEBUG
void CDialog10View::AssertValid() const
{
	CView::AssertValid();
}

void CDialog10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialog10Doc* CDialog10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialog10Doc)));
	return (CDialog10Doc*)m_pDocument;
}
#endif //_DEBUG


// CDialog10View 消息处理程序


void CDialog10View::OnShowDialog()
{
	// TODO: 在此添加命令处理程序代码
	Config dlg;
	if (dlg.DoModal() == IDOK)
	{
	}

}
