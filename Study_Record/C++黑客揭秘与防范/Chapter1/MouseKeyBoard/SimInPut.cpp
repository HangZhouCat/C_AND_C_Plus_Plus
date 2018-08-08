// SimInPut.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBoard.h"
#include "SimInPut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimInPut dialog


CSimInPut::CSimInPut(CWnd* pParent /*=NULL*/)
	: CDialog(CSimInPut::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimInPut)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSimInPut::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimInPut)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSimInPut, CDialog)
	//{{AFX_MSG_MAP(CSimInPut)
	ON_BN_CLICKED(IDC_BTN_KeyBoard, OnBTNKeyBoard)
	ON_BN_CLICKED(IDC_BTN_Mouse, OnBTNMouse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimInPut message handlers

void CSimInPut::FindAndFocus()
{
	GetDlgItemText(IDC_EDIT_CAPTION,m_StrCaption);
	//判断输入是否为空
	if (m_StrCaption == "")
	{
		AfxMessageBox("输入为空，请重新输入");
		return;
	}
	m_hWnd = ::FindWindow(NULL,m_StrCaption.GetBuffer(0));
	//该函数将创建指定窗口的线程设置到前台,并且激活该窗口
	::SetForegroundWindow(m_hWnd);
	
}

void CSimInPut::OnBTNKeyBoard() 
{
	// TODO: Add your control notification handler code here
	//模拟键盘操作
	//找到窗口
	//将其设置到前台并激活

	FindAndFocus();
	Sleep(1000);
	//模拟F5三次
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
}

void CSimInPut::OnBTNMouse() 
{
	// TODO: Add your control notification handler code here
	//模拟鼠标操作
	
	FindAndFocus();
	//得到窗口在屏幕的坐标(x,y)
	POINT pt = {0};
	::ClientToScreen(m_hWnd,&pt);
	//设置鼠标位置
	SetCursorPos(pt.x + 36,pt.y + 395);
	//模拟鼠标右键
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	Sleep(3000);
	//0x52 = R
	//在弹出右键菜单后按下R键
	//会刷新页面
	keybd_event(0x52,0,0,0);

}
