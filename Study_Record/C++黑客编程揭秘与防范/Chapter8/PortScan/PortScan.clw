; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPortScanDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PortScan.h"

ClassCount=3
Class1=CPortScanApp
Class2=CPortScanDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PORTSCAN_DIALOG

[CLS:CPortScanApp]
Type=0
HeaderFile=PortScan.h
ImplementationFile=PortScan.cpp
Filter=N

[CLS:CPortScanDlg]
Type=0
HeaderFile=PortScanDlg.h
ImplementationFile=PortScanDlg.cpp
Filter=D
LastObject=CPortScanDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PortScanDlg.h
ImplementationFile=PortScanDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PORTSCAN_DIALOG]
Type=1
Class=CPortScanDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_IPADDRESS_TargetIP,SysIPAddress32,1342242816
Control5=IDC_EDIT_StartPort,edit,1350631552
Control6=IDC_EDIT_EndPort,edit,1350631552
Control7=IDC_BUTTON_Scan,button,1342242816
Control8=IDC_LIST_Ports,listbox,1352728835

