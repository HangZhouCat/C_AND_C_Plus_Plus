; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSimInPut
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MouseKeyBoard.h"

ClassCount=5
Class1=CMouseKeyBoardApp
Class2=CMouseKeyBoardDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_BoradRefresh
Resource2=IDR_MAINFRAME
Resource3=IDD_MOUSEKEYBOARD_DIALOG
Class4=BoardRefresh
Resource4=IDD_ABOUTBOX
Class5=CSimInPut
Resource5=IDD_SimInput

[CLS:CMouseKeyBoardApp]
Type=0
HeaderFile=MouseKeyBoard.h
ImplementationFile=MouseKeyBoard.cpp
Filter=N

[CLS:CMouseKeyBoardDlg]
Type=0
HeaderFile=MouseKeyBoardDlg.h
ImplementationFile=MouseKeyBoardDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMouseKeyBoardDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MouseKeyBoardDlg.h
ImplementationFile=MouseKeyBoardDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOUSEKEYBOARD_DIALOG]
Type=1
Class=CMouseKeyBoardDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

[DLG:IDD_BoradRefresh]
Type=1
Class=BoardRefresh
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CAPTION,edit,1350631552
Control5=IDC_EDIT_INTERVAL,edit,1350631552

[CLS:BoardRefresh]
Type=0
HeaderFile=BoardRefresh.h
ImplementationFile=BoardRefresh.cpp
BaseClass=CDialog
Filter=D
LastObject=BoardRefresh
VirtualFilter=dWC

[DLG:IDD_SimInput]
Type=1
Class=CSimInPut
ControlCount=4
Control1=IDC_BTN_KeyBoard,button,1342242817
Control2=IDC_BTN_Mouse,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CAPTION,edit,1350631552

[CLS:CSimInPut]
Type=0
HeaderFile=SimInPut.h
ImplementationFile=SimInPut.cpp
BaseClass=CDialog
Filter=D
LastObject=CSimInPut
VirtualFilter=dWC

