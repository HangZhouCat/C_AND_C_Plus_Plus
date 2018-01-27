// MyTcpTran.cpp: implementation of the CMyTcpTran class.
//
//////////////////////////////////////////////////////////////////////

#include "MyTcpTran.h"

using namespace std;






//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/************************************************************************/
/* 类名: CMyTCPTran
   功能: 完成TCP的通信                                                    */
/************************************************************************/

//构造函数
CMyTcpTran::CMyTcpTran()
{

//套接字返回INVALID_SOCKET,则认为该套接字无效，这里在构造函数中为成员变量默认赋值为无效的套接字，起到初始化的作用
	m_Socket = INVALID_SOCKET;



}

//析构函数
CMyTcpTran::~CMyTcpTran()
{


//


}




/************************************************************************/
/* 函数名：InitSocketLibray
   功能: 初始化Socket的通信库,要求Winsock2
   参数:	lowver：版本的低位
			higver: 版本的高位    
   返回值:		TRUE表示成功，FALSE表示失败。                                                                 */
/************************************************************************/
BOOL CMyTcpTran::InitSocketLibray(int lowver,int higver)
{


	WORD wVersion = 0;
	int errret = -1;
	WSADATA wsaData;

	//MAKEWORD将两个byte型合并成一个word型,在这里一个是版本的低8位，一个是版本的高8位

	//高位字节指明副版本，低位字节指明主版本，如果一个程序使用2.1版本的Socket，则代码如下。
	//wVersion = MAKEWORD(2,1);
	
	wVersion = MAKEWORD(lowver,higver);

	//加载和初始化Socket对应的动态链接库ws2_32.dll的一些信息，为使用Socket做准备。

	errret = WSAStartup(wVersion,&wsaData);

	//判断Socket对应的动态链接库的版本

	if (LOBYTE (wsaData,wVersion) != 2 ||
		HIBYTE(wsaData,wVersion) !=2
		)
	{

		MessageBox(NULL,"winsocket 库版本低","提示",MB_OK);
		return FALSE;

	}

	return TRUE;


}


/************************************************************************/
/* 函数名：InitSocket
   功能: 根据类型初始化Socket资源
   参数:	SocketType：SOCK_BIND 表示绑定本地端口
					SOCK_NOBIND 表示不绑定
			BindIp: 要绑定的IP地址,""为本地任意地址，点分十进制表示IP地址
			BindPort: 要绑定的本地端口，如果为0表示系统自动产生。
			opt: 用于是否支持端口重用。
   返回值:		TRUE表示成功，FALSE表示失败。                                                                 */
/************************************************************************/
