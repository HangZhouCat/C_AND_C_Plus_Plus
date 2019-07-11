// MouseKeyBoardDlg.h : header file
//

#if !defined(AFX_MOUSEKEYBOARDDLG_H__2E60E6F2_AE12_4375_824B_ABC8E8C0E143__INCLUDED_)
#define AFX_MOUSEKEYBOARDDLG_H__2E60E6F2_AE12_4375_824B_ABC8E8C0E143__INCLUDED_


#include "BoardRefresh.h"
#include "SimInPut.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBoardDlg dialog

class CMouseKeyBoardDlg : public CDialog
{
// Construction
public:
	CMouseKeyBoardDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMouseKeyBoardDlg)
	enum { IDD = IDD_MOUSEKEYBOARD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseKeyBoardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMouseKeyBoardDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBoardRefreshWebPage();
	afx_msg void OnSimInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEKEYBOARDDLG_H__2E60E6F2_AE12_4375_824B_ABC8E8C0E143__INCLUDED_)
