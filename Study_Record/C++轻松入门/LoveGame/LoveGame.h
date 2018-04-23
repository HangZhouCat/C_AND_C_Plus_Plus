// LoveGame.h : main header file for the LOVEGAME application
//

#if !defined(AFX_LOVEGAME_H__8E726567_20C8_40E5_B795_1D3CCC828E8F__INCLUDED_)
#define AFX_LOVEGAME_H__8E726567_20C8_40E5_B795_1D3CCC828E8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLoveGameApp:
// See LoveGame.cpp for the implementation of this class
//

class CLoveGameApp : public CWinApp
{
public:
	CLoveGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoveGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLoveGameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOVEGAME_H__8E726567_20C8_40E5_B795_1D3CCC828E8F__INCLUDED_)
