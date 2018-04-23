// CreateThreadDemoDlg.h : header file
//

#if !defined(AFX_CREATETHREADDEMODLG_H__9D2F6656_03BB_4115_8D88_CD53C67ABF4B__INCLUDED_)
#define AFX_CREATETHREADDEMODLG_H__9D2F6656_03BB_4115_8D88_CD53C67ABF4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateThreadDemoDlg dialog

class CCreateThreadDemoDlg : public CDialog
{
// Construction
public:
	CCreateThreadDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateThreadDemoDlg)
	enum { IDD = IDD_CREATETHREADDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateThreadDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateThreadDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnbtnCreateThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETHREADDEMODLG_H__9D2F6656_03BB_4115_8D88_CD53C67ABF4B__INCLUDED_)
