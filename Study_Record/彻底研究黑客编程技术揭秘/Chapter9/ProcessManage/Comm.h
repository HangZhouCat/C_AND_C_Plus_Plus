typedef struct tagLinkInfo {

		SOCKET s;			//进程通信Socket
		string strBindIp;		//网络中的主机iP
		u_short BindPort;		//网络中主机开启的服务器端口

}LINKINFO,*LPLINKINFO;

typedef struct tagProcessInfo {
	DWORD PID;			//进程ID
	char ProcName[64];		//进程名
	char ProcPath[128];		//进程路径
}PROCESSINFO,*LPPROCESSINFO;
