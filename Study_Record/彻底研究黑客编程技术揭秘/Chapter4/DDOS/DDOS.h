// DDOS.h: interface for the CDDOS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_)
#define AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WINSOCK2.H>
#include "protocol.h"
#pragma comment (lib,"ws2_32.lib")


#define BufferSize 1024			//预定义UDP缓冲区大小
#define PacketNum 4096
static char pSendBuffer[BufferSize+60];		//发送缓冲区

static char SendBuffer[PacketNum][60] = {0};
static int iTotalSize = 0;

class CDDOS  
{
public:
	CDDOS();		//构造函数
	virtual ~CDDOS();		//析构函数
	void udp_flood();		//UDP洪水攻击
	void syn_flood();		//SYN洪水攻击
	void tcp_flood();		//TCP多连接攻击
private:
	void fill_udp_buffer();
	void fill_syn_buffer();

};

#endif // !defined(AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_)
