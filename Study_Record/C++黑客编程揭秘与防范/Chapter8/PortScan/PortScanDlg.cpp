// PortScanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PortScan.h"
#include "PortScanDlg.h"

#include <WinSock2.h>
#pragma comment (lib,"ws2_32")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPortScanDlg dialog

CPortScanDlg::CPortScanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPortScanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPortScanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPortScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPortScanDlg)
	DDX_Control(pDX, IDC_LIST_Ports, m_ListPorts);
	DDX_Control(pDX, IDC_IPADDRESS_TargetIP, m_IpAddr);
	DDX_Control(pDX, IDC_BUTTON_Scan, m_BtnScan);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPortScanDlg, CDialog)
	//{{AFX_MSG_MAP(CPortScanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Scan, OnBUTTONScan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPortScanDlg message handlers

BOOL CPortScanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPortScanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPortScanDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPortScanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPortScanDlg::OnBUTTONScan() 
{
	// TODO: Add your control notification handler code here
	
	m_BtnScan.EnableWindow(FALSE);

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2),&wsaData);


	DWORD dwIpAddr = 0;	//IP地址
	WORD wStartPort = 0,wEndPort = 0,wCurrPort = 0;	//开始端口、结束端口、和当前端口
	
	m_IpAddr.GetAddress(dwIpAddr);	//得到IP地址框中的IP地址。
	
	//得到编辑框中的开始端口和结束端口号
	wStartPort = GetDlgItemInt(IDC_EDIT_StartPort,FALSE,FALSE);
	wEndPort = GetDlgItemInt(IDC_EDIT_EndPort,FALSE,FALSE);

	CTime starttime,endtime;

	//获得扫描开始时间
	starttime = CTime::GetCurrentTime();

	//逐个连接从开始端口到结束端口之间的所有端口
	for (wCurrPort = wStartPort; wCurrPort <= wEndPort; wCurrPort++)
	{


		SOCKET s = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

		struct sockaddr_in ServAddr;
		ServAddr.sin_family = AF_INET;
		ServAddr.sin_addr.S_un.S_addr = htonl(dwIpAddr);
		ServAddr.sin_port = htonl(wCurrPort);


		CString strPort;
		//连接当前端口
		if( connect(s,(SOCKADDR*) &ServAddr,sizeof(SOCKADDR) ) ==0 )
		{


			
			strPort.Format("[%d] is open", wCurrPort);
			m_ListPorts.AddString(strPort);


		}
		else
		{


			strPort.Format("[%d] is close", wCurrPort);
			m_ListPorts.AddString(strPort);

		}


		closesocket(s);

	}



	//获得扫描结束时间
	endtime = CTime::GetCurrentTime();
	
	//计算扫描花费的时间
	CTimeSpan t = endtime - starttime;
	CString str;
	str.Format("耗时：%02d:02d:02d", t.GetHours(),t.GetMinutes(), t.GetSeconds());

	m_ListPorts.AddString(str);

	m_BtnScan.EnableWindow(TRUE);

	WSACleanup();

}
