// Lesson1Dlg.h : header file
//

#if !defined(AFX_LESSON1DLG_H__22B3687C_9E6A_4CA8_BE75_76B4537953CA__INCLUDED_)
#define AFX_LESSON1DLG_H__22B3687C_9E6A_4CA8_BE75_76B4537953CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLesson1Dlg dialog

class CLesson1Dlg : public CDialog
{
// Construction
public:
	CLesson1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLesson1Dlg)
	enum { IDD = IDD_LESSON1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLesson1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLesson1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LESSON1DLG_H__22B3687C_9E6A_4CA8_BE75_76B4537953CA__INCLUDED_)
