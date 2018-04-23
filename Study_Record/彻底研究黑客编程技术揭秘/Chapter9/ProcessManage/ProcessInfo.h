//列举进程模块
#include "stdafx.h"
#include "windows.h"
#include <vector>
#include <TLHELP32.H>
#include "PSAPI.H"			//要有SDK支持调试，列举进程路径用
#pragma comment(lib,"PSAPI.LIB")

BOOL EnablePrivilege(HANDLE hToken,LPCSTR szPrivName)
{

	TOKEN_PRIVILEGES tkp;	//TOKEN_PRIVILEGES结构包含一组特权信息的访问令牌。
	//修改进程权限
	LookupPrivilegeValue(NULL,szPrivName,&tkp.Privileges[0].Luid);		//LookupPrivilegeValue函数检索本地唯一标识符(LUID)用于指定系统本地代表指定的特权的名字。
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	//通知系统修改进程权限
	AdjustTokenPrivileges(hToken,FALSE,&tkp,sizeof tkp,NULL,NULL);
	return ((GetLastError() == ERROR_SUCCESS));
}
BOOL GetProcessList(std::vector(PROCESSINFO*) *pProcInfo)
{

	DWORD processid[1024],needed;
	HANDLE hProcess;
	HMODULE hModule;
	

}