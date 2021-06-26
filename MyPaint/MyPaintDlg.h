// MyPaintDlg.h : header file

#pragma once

#include <vector>
#include <stack>
#include "MyShape.h"
#include "MyLine.h"
#include "MyEllipse.h"
#include "MyTriangle.h"
#include "MyRectangle.h"
#include "MySquare.h"
#include "Cache.h"

using namespace std;

enum {
	LINE,
	RECTANGLE,
	TRIANGLE,
	ELLIPSE,
	SQUARE,
};



// CMyPaintDlg dialog
class CMyPaintDlg : public CDialogEx
{
// Construction
public:
	CMyPaintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYPAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int type = LINE;

	vector<MyShape*> shapes;

	//stacks for redo and undo
	stack<Cache*> done, undone;

	bool isPressed;

	//colors
	COLORREF backGroundColor, borderColor;

	bool ifSelected;
	MyShape* tempShape;
	CPoint beginMove, endMove;

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
