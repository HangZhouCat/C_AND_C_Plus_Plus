// UserWMDlg.h : header file
//

#if !defined(AFX_USERWMDLG_H__6634E69C_9904_4F57_90C6_44524BFCEF2E__INCLUDED_)
#define AFX_USERWMDLG_H__6634E69C_9904_4F57_90C6_44524BFCEF2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUserWMDlg dialog

class CUserWMDlg : public CDialog
{
// Construction
public:
	CUserWMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUserWMDlg)
	enum { IDD = IDD_USERWM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserWMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUserWMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RevcMsg(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERWMDLG_H__6634E69C_9904_4F57_90C6_44524BFCEF2E__INCLUDED_)
