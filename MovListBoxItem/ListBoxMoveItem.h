#pragma once

#include "WndResizer_2.h"  
#include "afxwin.h"

#define MAX_SIZE_X_3 800;
#define MAX_SIZE_Y_3 1800;

#define MIN_SIZE_X_3 350;
#define MIN_SIZE_Y_3 300;

	static bool bOnceColumnsSelect = true;

class CListBoxMoveItem : public CDialog
{
	DECLARE_DYNAMIC(CListBoxMoveItem)

public:
	CListBoxMoveItem(CWnd* pParent = NULL);   
	CListBoxMoveItem( CWnd* pParent = NULL, CString sListColListCtrl = "", CString sListColSelection = "");	


	virtual ~CListBoxMoveItem();

	enum { IDD = IDD_DIALOG1 };

	CString Get_ListColListCtrl()	const { return m_sListColListCtrl; }	
	CString Get_ListColSelection()	const { return m_sListColSelection; }	
	CString Get_ListColDispo()		const { return m_sListColDispo; }		

	void Set_ListColListCtrl( CString sList )	{ m_sListColListCtrl =  sList; }	
	void Set_ListColSelection( CString sList )	{ m_sListColSelection =  sList; }	
	void Set_ListColDispo( CString sList )		{ m_sListColDispo =  sList; }		
	void FillListBox();		

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();


protected:
	

	virtual void DoDataExchange(CDataExchange* pDX);   

	void	ResizeInit();	

	void	MaJTextes();		
	void	Set_ListColDispo();	
	void	MoveDispoToSelect(int nIndex);
	void	MoveSelectToDispo(int nIndex);	


	CString m_sListColListCtrl;		
	CString m_sListColSelection;	
	CString m_sListColDispo;		

	CString m_sNbColListCtrl;	
	CString m_sNbColSelection;	
	CString m_sNbColDispo;		

	CString m_vNbDispo;
	CString m_vNbSel;	

	DECLARE_MESSAGE_MAP()

private:
  CWndResizer_2 m_resizer;

public:
	CListBox m_cListBox_Dispo;
	CListBox m_cListBox_Selection;


	afx_msg void OnBnClickedOk();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

};
