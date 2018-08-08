#if !defined(AFX_BOARDREFRESH_H__DED6B46C_0FA4_4018_A80F_FB8B59A2B0F9__INCLUDED_)
#define AFX_BOARDREFRESH_H__DED6B46C_0FA4_4018_A80F_FB8B59A2B0F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BoardRefresh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BoardRefresh dialog

class BoardRefresh : public CDialog
{
// Construction
public:
	BoardRefresh(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BoardRefresh)
	enum { IDD = IDD_BoradRefresh };
	CButton	m_Start;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BoardRefresh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BoardRefresh)
	afx_msg void OnBtnStart();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_strCaption;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOARDREFRESH_H__DED6B46C_0FA4_4018_A80F_FB8B59A2B0F9__INCLUDED_)
