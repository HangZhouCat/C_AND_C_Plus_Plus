// MouseKeyBoard.h : main header file for the MOUSEKEYBOARD application
//

#if !defined(AFX_MOUSEKEYBOARD_H__4B69C1C2_19D3_4C17_9A1A_F031C900F234__INCLUDED_)
#define AFX_MOUSEKEYBOARD_H__4B69C1C2_19D3_4C17_9A1A_F031C900F234__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBoardApp:
// See MouseKeyBoard.cpp for the implementation of this class
//

class CMouseKeyBoardApp : public CWinApp
{
public:
	CMouseKeyBoardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseKeyBoardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMouseKeyBoardApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEKEYBOARD_H__4B69C1C2_19D3_4C17_9A1A_F031C900F234__INCLUDED_)
