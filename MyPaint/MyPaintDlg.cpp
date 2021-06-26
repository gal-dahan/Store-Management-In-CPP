#include "stdafx.h"
#include "MyPaint.h"
#include "MyPaintDlg.h"
#include "afxdialogex.h"
#include "Cache.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


CMyPaintDlg::CMyPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyPaintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMyPaintDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMyPaintDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMyPaintDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMyPaintDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMyPaintDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyPaintDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyPaintDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyPaintDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyPaintDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyPaintDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyPaintDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyPaintDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMyPaintDlg message handlers

BOOL CMyPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	isPressed = false;
	ifSelected = false;

	MyShape *shape = new MyLine;

	backGroundColor = RGB(0, 100, 200);
	borderColor = RGB(200, 100, 0);
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	delete shape;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CMyPaintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		for (auto shape: shapes)
			shape->draw(dc);

		CDialogEx::OnPaint();
	}
}


HCURSOR CMyPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	MyShape *shape;

	switch (type)
	{
		case LINE:
			shape = new MyLine;
			break;
		case RECTANGLE:
			shape = new MyRectangle;
			break;
		case TRIANGLE:
			shape = new MyTriangle;
			break;
		case SQUARE:
			shape = new MySquare;
			break;
		case ELLIPSE:
			shape = new MyEllipse;
			break;
			default:
			shape = new MyLine;
			break;
	}

	shape->setBackGroundColor(backGroundColor);
	shape->setBorderColor(borderColor);

	Cache *cache = new Cache(shapes, shape);
	done.push(cache);
	cache->undo();

	shape->setBegin(MyPoint(point.x, point.y));
	isPressed = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMyPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isPressed = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMyPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	if (isPressed)
	{
		shapes[shapes.size() - 1]->setEnd(MyPoint(point.x, point.y));
		Invalidate();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

//Line
void CMyPaintDlg::OnBnClickedRadio1()
{
	type = LINE;
}

//Rectangle
void CMyPaintDlg::OnBnClickedRadio2()
{
	type = RECTANGLE;
}

//Ellipse
void CMyPaintDlg::OnBnClickedRadio3()
{
	type = ELLIPSE;
}

//Triangle
void CMyPaintDlg::OnBnClickedRadio4()
{
	type = TRIANGLE;
}

//Square 
void CMyPaintDlg::OnBnClickedRadio5()
{
	type = SQUARE;
}

//Background color
void CMyPaintDlg::OnBnClickedButton1()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		backGroundColor = dlg.GetColor();
	}
}

//Border color
void CMyPaintDlg::OnBnClickedButton2()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		borderColor = dlg.GetColor();
	}
}

// UNDO
void CMyPaintDlg::OnBnClickedButton3()
{
	if (done.empty())
		return;
	Cache *cache = done.top();
	done.pop();
	undone.push(cache);
	cache->redo();
	Invalidate();
}

// UNDO ALL-clear
void CMyPaintDlg::OnBnClickedButton4()
{
	while(!done.empty())
		OnBnClickedButton3();	
	return;
}

// REDO
void CMyPaintDlg::OnBnClickedButton5()
{
	if (undone.empty())
		return;
	Cache *cache = undone.top();
	undone.pop();
	done.push(cache);
	cache->undo();
	Invalidate();	
}

// SAVE
void CMyPaintDlg::OnBnClickedButton6()
{
	CFile file(L"shapes.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	archive << shapes.size();
	for (int i = 0; i < shapes.size(); ++i)
		archive << shapes[i];
}

//LOAD
void CMyPaintDlg::OnBnClickedButton7()
{
	CFile file(L"shapes.bin", CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	int count;
	archive >> count;
	for (int i = 0; i < count; ++i)
	{
		MyShape *s;
		archive >> s;
		shapes.push_back(s);
	}
	Invalidate();
}
