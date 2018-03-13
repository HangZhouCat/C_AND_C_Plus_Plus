//UDP攻击
#define BufferSize 1024			//预定义缓冲区大小
static char pSendBuffer[BufferSize+60];		//发送缓冲区
static int iTotalSize = 0;