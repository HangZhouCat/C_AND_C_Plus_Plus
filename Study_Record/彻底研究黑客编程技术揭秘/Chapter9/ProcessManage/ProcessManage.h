// ProcessManage.h : main header file for the PROCESSMANAGE application
//

#if !defined(AFX_PROCESSMANAGE_H__E5F272AB_6256_448B_83AC_FAFAE9419EEF__INCLUDED_)
#define AFX_PROCESSMANAGE_H__E5F272AB_6256_448B_83AC_FAFAE9419EEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcessManageApp:
// See ProcessManage.cpp for the implementation of this class
//

class CProcessManageApp : public CWinApp
{
public:
	CProcessManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcessManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSMANAGE_H__E5F272AB_6256_448B_83AC_FAFAE9419EEF__INCLUDED_)
