// TcpServer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")

int main()
{

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//创建套接字
	SOCKET sLisent = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	//对sockaddr_in结构体填充地址，端口等信息
	struct sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(666);

	//绑定套接字与地址信息
	bind(sLisent, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//端口监听
	listen(sLisent, SOMAXCONN);

	//获取连接请求
	sockaddr_in ClientAddr;
	int nSize = sizeof(ClientAddr);

	SOCKET sClient = accept(sLisent, (SOCKADDR*)&ClientAddr, &nSize);

	//输出客户端使用的IP地址和端口号
	printf("ClinetIP=%s:%d\r\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));




	getchar();
    return 0;
}

