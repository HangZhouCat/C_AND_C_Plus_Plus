// BoardRefresh.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBoard.h"
#include "BoardRefresh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BoardRefresh dialog


BoardRefresh::BoardRefresh(CWnd* pParent /*=NULL*/)
	: CDialog(BoardRefresh::IDD, pParent)
{
	//{{AFX_DATA_INIT(BoardRefresh)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BoardRefresh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BoardRefresh)
	DDX_Control(pDX, IDOK, m_Start);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BoardRefresh, CDialog)
	//{{AFX_MSG_MAP(BoardRefresh)
	ON_BN_CLICKED(IDOK, OnBtnStart)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BoardRefresh message handlers

void BoardRefresh::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CString strBtn;
	int nInterval = 0;		//时间间隔
	//获取输入的浏览器标题
	GetDlgItemText(IDC_EDIT_CAPTION,m_strCaption);
	//获取输入的刷新频率
	nInterval = GetDlgItemInt(IDC_EDIT_INTERVAL,FALSE,TRUE);
	//判断输入的值是否合法
	if (m_strCaption == "" || nInterval ==0)
	{
		return;
	}
	//获取按钮的标题
	m_Start.GetWindowText(strBtn);
	if (strBtn == "开始")
	{

		//设置定时器
		SetTimer(1,nInterval * 1000,NULL);
		m_Start.SetWindowText("停止");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(FALSE);
	}
	else
	{
		//结束定时器
		KillTimer(1);
		m_Start.SetWindowText("开始");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(TRUE);
	}
}

void BoardRefresh::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		//响应计时器的函数

	AfxMessageBox("Timer");

	HWND hWnd = ::FindWindow(NULL,m_strCaption.GetBuffer(0));

	if (hWnd == 0)
	{

		AfxMessageBox("未找到窗口句柄，稍后重试!");

	}
	else{
		AfxMessageBox("已经找到窗口句柄，马上刷新！");
	}

	//发送键盘按下
	::PostMessage(hWnd,WM_KEYDOWN,VK_F5,1);
	Sleep(50);		
	//发送键盘抬起
	::PostMessage(hWnd,WM_KEYUP,VK_F5,1);
	
	CDialog::OnTimer(nIDEvent);
}
