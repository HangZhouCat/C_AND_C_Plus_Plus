// Lesson1.h : main header file for the LESSON1 application
//

#if !defined(AFX_LESSON1_H__89A2AFE4_74E3_4FD0_9398_95F48E4494EE__INCLUDED_)
#define AFX_LESSON1_H__89A2AFE4_74E3_4FD0_9398_95F48E4494EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLesson1App:
// See Lesson1.cpp for the implementation of this class
//

class CLesson1App : public CWinApp
{
public:
	CLesson1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLesson1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLesson1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LESSON1_H__89A2AFE4_74E3_4FD0_9398_95F48E4494EE__INCLUDED_)
