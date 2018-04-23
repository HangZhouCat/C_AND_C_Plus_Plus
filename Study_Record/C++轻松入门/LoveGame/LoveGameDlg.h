// LoveGameDlg.h : header file
//

#if !defined(AFX_LOVEGAMEDLG_H__E95B263B_9695_4668_967B_5CE32BFD1AF2__INCLUDED_)
#define AFX_LOVEGAMEDLG_H__E95B263B_9695_4668_967B_5CE32BFD1AF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLoveGameDlg dialog

class CLoveGameDlg : public CDialog
{
// Construction
public:
	CLoveGameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLoveGameDlg)
	enum { IDD = IDD_LOVEGAME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoveGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLoveGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOVEGAMEDLG_H__E95B263B_9695_4668_967B_5CE32BFD1AF2__INCLUDED_)
