#if !defined(AFX_SIMINPUT_H__11769F58_02DE_4E83_870F_20417E530BF6__INCLUDED_)
#define AFX_SIMINPUT_H__11769F58_02DE_4E83_870F_20417E530BF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SimInPut.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimInPut dialog

class CSimInPut : public CDialog
{
// Construction
public:
	CSimInPut(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSimInPut)
	enum { IDD = IDD_SimInput };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimInPut)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSimInPut)
	afx_msg void OnBTNKeyBoard();
	afx_msg void OnBTNMouse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FindAndFocus();
	CString m_StrCaption;
	HWND m_hWnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMINPUT_H__11769F58_02DE_4E83_870F_20417E530BF6__INCLUDED_)
