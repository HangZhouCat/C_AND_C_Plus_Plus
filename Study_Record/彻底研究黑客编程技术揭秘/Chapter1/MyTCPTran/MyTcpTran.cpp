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
   返回值:		错误:INVALID_SOCKET
                正确：返回可用的SOCKET                                            */
/************************************************************************/
SOCKET CMyTcpTran::InitSocket(int SocketType,string strBindIp, u_short BindPort,int opt)
{

	SOCKET socketid = INVALID_SOCKET;
	//创建一个能够进行网络通信的套接字

	socketid = socket(PF_INET,SOCK_STREAM,0);

	SOCKADDR_IN sockStruct;

	//使用TCP/IP协议
	sockStruct.sin_family = AF_INET;
	if (strBindIp.empty())
	{

		//参数strBindIp为空，则用INADDR_ANY 表示Socket可用接收来自任何IP的消息
		sockStruct.sin_addr.S_un.S_addr = INADDR_ANY;

	}
	else
	{

		//参数strBindIp不为空，将strBindIp转换为char*后
		//将IP地址从点数格式转换成无符号长整型
		sockStruct.sin_addr.S_un.S_addr = inet_addr(strBindIp.c_str());

	}

	//将参数BindPort转换为网络字节序后保存
	sockStruct.sin_port = htons(BindPort);

	//不绑定端口
	if ( SocketType == SOCKETNOBIND )
	{

		//与sockStruct结构所指定的网络上的计算机进行连接

		if (connect(socketid,(LPSOCKADDR)&sockStruct,sizeof(sockStruct))  == 
			SOCKET_ERROR
			)
		{


			//与网络上的计算机连接失败
			//OutputDebugString("连接错误！");
			closesocket(socketid);

			//关闭以及打开的Socket套接字，防止占用内存。
			shutdown(socketid,2);

			//设置套接字无效

			socketid = INVALID_SOCKET；

		}
		m_Socket = socketid;

	}

//如果是绑定本地端口
else if ( SocketType == SOCKETBIND )
{

	//绑定由sockStruct指定的网络计算机的IP和端口

	if (bind(socketid,(sockaddr*)&sockStruct,sizeof(sockaddr_in)) == 
		SOCKET_ERROR
		)
	{

		//绑定端口失败
		closesocket(socketid);

		//设置套接字无效

		socketid = INVALID_SOCKET;

	}else
	{

		//绑定IP和端口成功，监听来自网络其他计算机的连接队列
		//SOMXCONN指明最大的连接数

		if ( listen(socketid,SOMAXCONN) == SOCKET_ERROR )
		{

			//监听函数调用失败，则关闭套接字，并设置套接字无效状态
			closesocket(socketid);
			socketid = INVALID_SOCKET;

		}

	}

	m_Socket = socketid;

}

	return socketid;

}

/************************************************************************/
/* 函数名：myaccept
   功能: 创建一个新的套接字与参数addr指定的客户端套接字建立连接通道
   参数:	s：		处于监听状态的流套接字
					SOCK_NOBIND 表示不绑定
			BindIp: 要绑定的IP地址,""为本地任意地址，点分十进制表示IP地址
			BindPort: 要绑定的本地端口，如果为0表示系统自动产生。
			opt: 用于是否支持端口重用。
   返回值:		错误:INVALID_SOCKET
                正确：返回可用的SOCKET                                            */
/************************************************************************/

SOCKET CMyTcpTran::myaccept(SOCKET sock, const char *buf, int len,int flag,int overtime)
{
	
	//创建新的套接字并初始化为INVALID_SOCKET
	SOCKET acceptsocket = INVALID_SOCKET;
	//accept调用成功返回可用的套接字，调用失败同样返回INVALID_SOCKET
	acceptsocket = accept(sock,addr,addrlen);

	return acceptsocket；

}

/************************************************************************/
/* 函数名：myrecv
   功能: 根据类型初始化Socket资源
   参数:	sock：		接收端套接字描述符 
			buf:		用来存放接收到的数据的缓冲区
			len:		接收到数据的大小
			flag:		一般设置为0
			overtime:	超时时间
			EndMark:	结束标识
			Soonflag:	是否立即返回
   返回值:	接收到的数据的字节数。                                       */
/************************************************************************/
int CMyTcpTran::myrecv(SOCKET sock,const *buf,int len,int flag,int overtime,char *EndMark, BOOL soonflag)
{

	//定义变量
	int ret;
	int nLeft = len;
	int idx = 0;
	int nCount = 0;
	fd_set readfds;			//fd_set是文件描述符的集合。
	struct timeval timeout;
	timeout.tv_sec = 0;		//设置超时值
	timeout.tv_usec = 500;
	DWORD s_time = GetTickCount();		//返回从操作系统启动到现在经过的毫秒数

	while ( nLeft >0 )
	{

		//接收消息
		MSG msg;
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		//接收到的消息是退出消息
		if (msg.message == WM_QUIT)
		{

			return 0;

		}

		FD_ZERO(&readfds);			//将set清零
		FD_SET(sock, &readfds);		//将fd加入set

		//select函数是用来管理套接字I/O的，避免出现无辜锁定

		if ( select(0, &readfds, NULL, NULL, &timeout) == SOCKET_ERROR )
		{

			return SOCKET_ERROR;

		}
		
		DWORD e_time = GetTickCount();
		if ( !FD_ISSET(sock, &readfds) )
		{

			if ( e_time - s_time > overtime * 1000 )		//超时
			{

				return SOCKET_ERROR;

			}
			else
			{

				continue;

			}

		}

		ret = recv( sock, &buf[idx], nLeft, flag );			//接收数据

		if ( soonflag == TRUE )
		{

			//立即返回接收到的字节数
			return ret;

		}

		
		s_time = e_time;		//只要有数据就重置初始时间值

		if ( ret <= 0 )
		{

			//错误处理
			int LastError = GetLastError();
			if ( ( -1 ==ret ) && (WSAETIMEDOUT == LastError) )
			{

				 if ( nCount < 2000 )
				 {

					Sleep( 10 );
					nCount++;
					continue;

				 }

			}
			return ret;

		}
		nCount = 0;

		nLeft -= ret;
		idx += ret;

		if ( EndMark != NULL && idx >5 )
		{


			if ( strstr(buf + (idx-5),EndMark) != NULL)
			{

				break;

			}

		}

	}

	return idx;


}

/************************************************************************/
/* 函数名：mysend
   功能: 用指定的Socket发送数据
   参数:	sock：	发送端套接字描述符
			buf:		用来存放发送数据的缓冲区
			flag:		一般设置为0
			overtime:	超时时间
   返回值:	实际发送数据的字节数。                                       */
/************************************************************************/
int CMyTcpTran::mysend(SOCKET sock,const char *buf,int len,int flag,int overtime)
{

//定义变量
int ret;
int nLeft = len;
int idx = 0;


fd_set readfds;
struct timeval timeout;
timeout.tv_sec = 0;
timeout.tv_usec = 500;
DWORD s_time = GetTickCount();


while ( nLeft > 0 )
{

	//向对话框发送关闭消息
	MSG msg;
	PeekMessage(&msg, NULL, 0,0,PM_REMOVE);
	if ( msg.message == WM_QUIT )
	{

		return 0;

	}

	FD_ZERO(&readfds);
	FD_SET(sock, &readfds);

	int errorret = select(0,NULL,&readfds, NULL, &timeout);

	if (errorret == SOCKET_ERROR)
	{

		OutputDebugString("mysendEx SOCKET 错误");
		return SOCKET_ERROR;

	}
	//计算当前时间
	DWORD e_time = GetTickCount();
	if (!FD_ISSET(sock,&readfds))
	{

		//如果超时，返回
		if (e_time - s_time > overtime * 1000)
		{


			OutputDebugString("mysendEx发送数据超时");
			return 0;

		}
		else
		{

			continue;
			
		}
		
	}
	ret = send(sock,&buf[idx], nLeft,flag);

	if ( ret <= 0 )
	{

		return ret;
		
	}

	nLeft -= ret;
	idx += ret;
	

}

	
return len;


}