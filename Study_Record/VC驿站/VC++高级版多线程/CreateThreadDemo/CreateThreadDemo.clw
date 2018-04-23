; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCreateThreadDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CreateThreadDemo.h"

ClassCount=4
Class1=CCreateThreadDemoApp
Class2=CCreateThreadDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CREATETHREADDEMO_DIALOG

[CLS:CCreateThreadDemoApp]
Type=0
HeaderFile=CreateThreadDemo.h
ImplementationFile=CreateThreadDemo.cpp
Filter=N

[CLS:CCreateThreadDemoDlg]
Type=0
HeaderFile=CreateThreadDemoDlg.h
ImplementationFile=CreateThreadDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CreateThreadDemoDlg.h
ImplementationFile=CreateThreadDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CREATETHREADDEMO_DIALOG]
Type=1
Class=CCreateThreadDemoDlg
ControlCount=1
Control1=IDC_btn_CreateThread,button,1342242816

