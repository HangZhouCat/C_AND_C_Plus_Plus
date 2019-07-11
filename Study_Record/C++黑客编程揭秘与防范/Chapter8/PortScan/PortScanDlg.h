// PortScanDlg.h : header file
//

#if !defined(AFX_PORTSCANDLG_H__C913DE5D_2084_472E_A2AC_8190F7C3592B__INCLUDED_)
#define AFX_PORTSCANDLG_H__C913DE5D_2084_472E_A2AC_8190F7C3592B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPortScanDlg dialog

class CPortScanDlg : public CDialog
{
// Construction
public:
	CPortScanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPortScanDlg)
	enum { IDD = IDD_PORTSCAN_DIALOG };
	CListBox	m_ListPorts;
	CIPAddressCtrl	m_IpAddr;
	CButton	m_BtnScan;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortScanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPortScanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONScan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTSCANDLG_H__C913DE5D_2084_472E_A2AC_8190F7C3592B__INCLUDED_)
