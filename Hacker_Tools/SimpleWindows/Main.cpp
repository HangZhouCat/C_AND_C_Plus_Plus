
#include <windows.h>



ATOM MyRegisterClass(HINSTANCE hInstance)
{


	WNDCLASSEX WndCls;

	//填充结构体为0

	ZeroMemory(&WndCls, sizeof(WNDCLASSEX));

	//cbSize是结构体大小

	WndCls.cbSize = sizeof(WNDCLASSEX);

	//lpfnWndProc是窗口过程地址

	WndCls.lpfnWndProc = WindowProc;

	//hInstance是实例句柄

	WndCls.hInstance = hInstance;

	//lpszClassName是窗口类类名

	WndCls.lpszClassName = CLASSNAME;

	//style是窗口类风格

	WndCls.style = CS_HREDRAW | CS_VREDRAW;

	//hbrBackground是窗口类背景色

	WndCls.hbrBackground = (HBRUSH) COLOR_WINDOW + 1;

	//hCursor是鼠标句柄

	WndCls.hCursor = LoadCursor(NULL,IDC_ARROW);

	//hIcon是图标句柄

	WndCls.hIcon = LoadIcon(NULL, IDI_QUESTION);

	//其他

	WndCls.cbClsExtra = 0;
	WndCls.cbWndExtra = 0;

	return RegisterClassEx(&WndCls);

}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


	HWND hWnd = NULL;

	

	
	//创建窗口



	
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
					CLASSNAME,
					"My First Window",
					
		
		)


}

int WINAPI WinMain ( HINSTANCE hInstance,		//应用程序的实例句柄
					HINSTANCE hPrevInstance,	//同一个文件创建的上一个实例的实例句柄
					LPSTR lpCmdLine,			//是主函数的参数，用于在程序启动时给进程传递参数。
					int nShowCmd				//是进程显示方式，可以是最大化、最小化显示，或者是隐藏等显示方式。
					)
{

	MSG Msg;
	BOOL bRet;

	//注册窗口类

	MyRegisterClass(hInstance);

	//创建窗口并显示窗口

	if ( ! InitInstance(hInstance, SW))
	{
	}





}