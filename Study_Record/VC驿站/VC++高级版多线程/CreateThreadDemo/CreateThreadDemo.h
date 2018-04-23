// CreateThreadDemo.h : main header file for the CREATETHREADDEMO application
//

#if !defined(AFX_CREATETHREADDEMO_H__CE9C086D_5102_4439_A42B_D2406E05B609__INCLUDED_)
#define AFX_CREATETHREADDEMO_H__CE9C086D_5102_4439_A42B_D2406E05B609__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateThreadDemoApp:
// See CreateThreadDemo.cpp for the implementation of this class
//

class CCreateThreadDemoApp : public CWinApp
{
public:
	CCreateThreadDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateThreadDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateThreadDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETHREADDEMO_H__CE9C086D_5102_4439_A42B_D2406E05B609__INCLUDED_)
