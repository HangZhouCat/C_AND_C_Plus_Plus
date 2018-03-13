#include <stdio.h>
#include <winsock.h>

//加载必须的头文件和库文件
#pragma comment(lib,"ws2_32")

//自定义帮助函数
void usage(char *prog)
{

	printf("Usage:GSGBannerScan.exe 127.0.0.1 65535\n");
	printf("GSGBannerScan.exe IP Startport Endport\n");

}

int main(int argc,char *argv[])
{

	
		if (argc != 4)
		{

			usage(argv[0]);
			return -1;

		}//如果参数不是4个，显示帮助


WSADATA wsa;

//初始化Socket版本
if ( WSAStartup(MAKEWORD(2,2), &wsa)  != 0 )
{


		printf("Winsock Dll init Failed!\n");
		return -1;

}
//定义当前端口和计数器
int nowport,count;

//设置开始端口和结束端口
struct sockaddr_in sa;
int startport = atoi(argv[2]);
int endport = atoi(argv[3]);

//判断端口有效性
if ( endport < startport )
{
	

		printf("don't doing, endport < startport\n");
		return -1;

}

//设置当前端口=开始端口
nowport = startport;
printf("Start Scan.....\n");
for (nowport;nowport < endport;nowport++)
{

		//设置目标主机信息
		sa.sin_family = AF_INET;
		sa.sin_addr.S_un.S_addr = inet_addr(argv[1]);
		sa.sin_port = htons(nowport);

		//建立Socket套接字
		SOCKET sockFD = socket(AF_INET,SOCK_STREAM,0);
		if (sockFD == INVALID_SOCKET)
		{

			printf("Socket create Error!\n");
			return -1;

		}

		int iTimeOut = 5000;		//设置超时
		setsockopt(sockFD,SOL_SOCKET,SO_RCVTIMEO,(char*)&iTimeOut,sizeof(iTimeOut));
		if (connect())
		{
		}

}


}
