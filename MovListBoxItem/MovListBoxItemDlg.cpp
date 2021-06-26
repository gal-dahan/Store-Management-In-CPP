

#include "stdafx.h"
#include "MovListBoxItem.h"
#include "MovListBoxItemDlg.h"
#include"typeinfo"
#include "ListBoxMoveItem.h"
#include"Jewel.h"
#include"Pants.h"
#include"Shirt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()




CMovListBoxItemDlg::CMovListBoxItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMovListBoxItemDlg::IDD, pParent)
	, m_vCompleteList(_T(""))
	, m_vChoosenList(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMovListBoxItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_vCompleteList);
	DDX_Text(pDX, IDC_EDIT2, m_vChoosenList);
}

BEGIN_MESSAGE_MAP(CMovListBoxItemDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_MOVE, &CMovListBoxItemDlg::OnBnClickedMove)
END_MESSAGE_MAP()



BOOL CMovListBoxItemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	//Polymorphism
	Item* arr[15];//arr for Complete List				  
	arr[0] = new Pants("Jeans", 'S');
	arr[1] = new Pants("Jeans", 'M');
	arr[2] = new Pants("Pants", 'L');
	arr[3] = new Pants("Pants", 'S');
	arr[4] = new Pants("Pants", 'S');
	arr[5] = new Pants("Jeans", 'L');
	arr[6] = new Shirt("T-shirt", 'M');
	arr[7] = new Shirt("Shirt", 'M');
	arr[8] = new Shirt("Shirt", 'S');
	arr[9] = new Shirt("Shirt", 'M');
	arr[10] = new Shirt("POLO",'S');
	arr[11] = new Shirt("Shirt",'M');
	arr[12] = new Shirt("T-shirt",'L');
	arr[13] = new Jewel("Necklaces"); 
	arr[14] = new Jewel("Watch");

	Clothes* c;
	m_vCompleteList = "";
	CString sTemp = "";
	CString sizeTemp = " ";
	
	int is_Clothes;
	for (int i = 0; i < 15; i ++)
	{
		is_Clothes = 0;
		sTemp.Format(" %g", arr[i]->get_price());	//Convert double to CString ;	
		if (typeid(arr[i])!=typeid(Clothes)){
			c = dynamic_cast<Clothes*>(arr[i]);//dynamic_cast if not Clothes sizeTemp=null
			is_Clothes = 1;
			sizeTemp = " NULL";
			if (c)
			{
				sizeTemp.Format("%c", c->get_size());	//Convert double to CString ;	


			}

		}

		if ( m_vCompleteList == "")
		{
			if (is_Clothes == 1) {
				m_vCompleteList = arr[i]->get_name() + sTemp  +" * " + sizeTemp + " * " + '\n';

			}
			else
			{
				m_vCompleteList = arr[i]->get_name() + sTemp +" * "+ sizeTemp + " * " + '\n';

			}
		}
		else
		{
			if (is_Clothes == 1) {
				m_vCompleteList = m_vCompleteList + "," + arr[i]->get_name() + sTemp + " * " + sizeTemp + " * " + '\n';

			}
			else {
				m_vCompleteList = m_vCompleteList + "," + arr[i]->get_name() + sTemp + " ** " + sizeTemp + " * " + '\n';

			}
		}
	}

	m_vChoosenList = "Pants 80 *M*,T-shirt 80 *L*,Watch 20 *NULL*";

	UpdateData( FALSE );	

	return TRUE;  
}

void CMovListBoxItemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}



void CMovListBoxItemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialog::OnPaint();
	}
}

HCURSOR CMovListBoxItemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMovListBoxItemDlg::OnBnClickedMove()
{
	UpdateData( TRUE );	
	CListBoxMoveItem dialog(this, m_vCompleteList, m_vChoosenList);
	if (dialog.DoModal() == IDOK)
	{
		m_vChoosenList = dialog.Get_ListColSelection();
	}
	delete dialog;
	UpdateData( FALSE );	
}