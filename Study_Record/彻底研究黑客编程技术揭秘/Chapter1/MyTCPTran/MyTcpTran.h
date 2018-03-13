// MyTcpTran.h: interface for the CMyTcpTran class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_)
#define AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define SOCKETBIND 1		//服务器端监听本地端口等待客户端连接通信方式
#define SOCKETNOBIND 2		//服务器端主动连接客户端通信方式
#define SOCKET_TIMEOUT -100		//套接字超时

#include <WINSOCK2.H>		//Winsock API所需要的头文件
#include <string.h>			//使用string类型所需要的头文件
using namespace std;

#pragma comment (lib,"ws2_32.lib")	//Winsock API 链接库文件

class CMyTcpTran  
{
public:
	CMyTcpTran();					//构造函数
	virtual ~CMyTcpTran();			//析构函数

public：
		static BOOL InitSocketLibray(int lowver, int higver);	//初始化Windows API连接库文件

public:
	//初始化socket函数
	SOCKET InitSocket(int SocketType,string strBindIp, u_short BindPort,int opt);

	//针对本地监听的处理函数
	SOCKET myaccept(SOCKET sock, const char *buf, int len,int flag,int overtime);

	//向服务器端/客户端发送数据/命令函数
	int mysend(SOCKET sock,const char *buf,int len,int flag,int overtime);

	//接收从客户端/服务器端发来的数据/命令函数
	int myrecv(SOCKET sock,const *buf,int len,int flag,int overtime,char *EndMark, BOOL soonflag=FALSE);

private:
	SOCKET m_Socket;		//私有套接字成员变量

};

#endif // !defined(AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_)
