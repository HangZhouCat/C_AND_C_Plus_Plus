#ifndef  _PROTOCAL_H
#define  _PROTOCAL_H



#define  ETHER_HEADER_LENGTH   0x0e                     //以太网头长度 
#define  IP_HEADER_LENGTH      0x14                     //IP头部的长度
#define  TCP_HEADER_LENGTH     0x14                     //TCP头部长度
#define  TCP_DATA_LENGTH       0x00   //0x10                     //TCP数据部分长度  
#define  PSD_LENGTH            0x0c                     //PSD伪首部长度


//32位的IP地址
typedef  struct tagIP_ADDRESS
{
	unsigned   char   byte1;
	unsigned   char   byte2;
	unsigned   char   byte3;
	unsigned   char   byte4;
}IP_ADDRESS,* LPIP_ADDRESS;


//48位的MAC地址
typedef struct tagHARD_MAC
{
	unsigned   char   byte1;
	unsigned   char   byte2;
	unsigned   char   byte3;
	unsigned   char   byte4;
	unsigned   char   byte5;
	unsigned   char   byte6;
}HARD_MAC,* LPHARD_MAC;


//以太网头部14个字节
typedef  struct  tagETHERNET_HEADER
{
	HARD_MAC	 dmac;                   //以太网目的地址
	HARD_MAC     smac;                   //以太网源地址
	WORD         type;                   //帧类型  IP数据包：0x0800   ARP包：0x0806   RARP包：0x8035       
}ETHERNET_HEADER,* LPETHERNET_HEADER;


//ARP帧，60个字节，不包含4个CRC校验位  
typedef   struct tagARP_FRAME
{
	ETHERNET_HEADER	    frameheader;      //以太网头部14个字节
	WORD                hardtype;         //硬件类型2个字节
	WORD                protype;          //协议类型2个字节
	unsigned  char      hardlength;       //硬件地址长度1个字节
	unsigned  char      prolength;        //协议地址长度1个字节
	WORD                oper;             //操作选项     1:请求   2：应答
	HARD_MAC	        smac;             //发送者硬件地址  6个字节 
	IP_ADDRESS		    saddr;            //发送者ip地址   4个字节
	HARD_MAC	        dmac;             //目标硬件地址  6个字节 
	IP_ADDRESS		    daddr;            //发送者ip地址  4个字节
	BYTE                padding[18];      //填充0
}ARP_FRAME,* LPARP_FRAME;


//IP数据包的头部   
typedef  struct  tagIP_HEADER
{
	unsigned   char	  ver_ihl;          //version  (4 bits) +Internet header  length(4 bits)  版本(4) + 首部长度(1个单位4个字节)
	unsigned   char   tos;              //Type  of  service   区分服务
	unsigned   short  tlen;             //Total length    总长度（IP头部+数据部分的长度） 总长度字段为16位，因此数据报的最大长度为2^16-1=65535字节  
	unsigned   short  identification;   //Identification   标识
	unsigned   short  flags_of;         //Flags (3 bits) + Fragment offsets (13 bits)  标志 片偏移
	unsigned   char   ttl;              //Time to live  生存时间
	unsigned   char   proto;            //Protocol   协议
	unsigned   short  crc;              //Header  checksum  首部校验和
	IP_ADDRESS        saddr;            //源地址  
	IP_ADDRESS        daddr;            //目的地址
	//unsigned   int    op_pad;           //Options + Padding   可选字段 + 填充
}IP_HEADER,* LPIP_HEADER;


//TCP数据包头部
typedef  struct tagTCP_HEADER
{
	unsigned  short sport;				// 源端口号16bit
    unsigned  short dport;				// 目的端口号16bit
    unsigned  int   seq;				// 序列号32bit 来标识从TCP源端向TCP目标端发送的数据字节流，它表示在这个报文段中的第一个数据字节。
    unsigned  int   ack;				// 确认号32bit 只有ACK标志为1时，确认号字段才有效。它包含目标端所期望收到源端的下一个数据字节。
	unsigned  char  offset;             // 前4位：TCP头长度 给出头部占32比特的数目。没有任何选项字段的TCP头部长度为20字节；最多可以有60字节的TCP头部。
	unsigned  char  flag;               // 中6位：保留
										// 后6位：标志位
										// 标志位字段（U、A、P、R、S、F）：占6比特。各比特的含义如下：
										// URG: 紧急指针（urgent pointer）有效
										// ACK：确认序号有效
										// PSH：接收方应该尽快将这个报文段交给应用层。
										// RST：重建连接。
										// SYN：发起一个连接。
										// FIN：释放一个连接。
	//定义TCP包头标志位
	#define   TCP_URG              0x01<<5
	#define   TCP_ACK              0x01<<4
	#define   TCP_PSH              0x01<<3 
	#define   TCP_RST              0x01<<2
	#define   TCP_SYN              0x01<<1
	#define   TCP_FIN              0x01<<0
    unsigned  short window;             // 窗口大小16bit 此字段用来进行流量控制。单位为字节数，这个值是本机期望一次接收的字节数。
    unsigned  short checkcum;           // 检验和16bit 占16比特。对整个TCP报文段，即TCP头部和TCP数据进行校验和计算，并由目标端进行验证。
    unsigned  short surgentpointer;     // 紧急数据偏移量16bit	它是一个偏移量，和序号字段中的值相加表示紧急数据最后一个字节的序号。
}TCP_HEADER,*LPTCP_HEADER;


//由于TCP首部中不包含源地址与目标地址等信息，为了保证TCP校验的有效性，在进行TCP校验和的计算时，需要增加一个TCP伪首部的校验和，定义如下：
typedef  struct  tagPSD_HEADER
{
	unsigned    long   saddr;   //源地址 4
	unsigned    long   daddr;   //目的地址 4
	unsigned	char   mbz;     //置空	 1
	unsigned	char   ptoto;   //协议类型 1
	unsigned	short  tcpl;    //TCP总长度  2
	TCP_HEADER  th;             //TCP头部  
	unsigned    char   data[TCP_DATA_LENGTH];  //数据
}PSD_HEADER,*LPSD_HEADER;

//IP帧（TCP）
typedef   struct tagIP_TCP_FRAME
{
	ETHERNET_HEADER    frameheader;				 //以太网头部14个字节
	IP_HEADER          ih;						 //IP头部
	union{
		struct{
			TCP_HEADER		   th;						 //TCP头部
			unsigned    char   data[TCP_DATA_LENGTH];	 //数据
		}tcp_fk;
		unsigned  char tcpall[TCP_HEADER_LENGTH+TCP_DATA_LENGTH];    
	}TCP;
}IP_TCP_FRAME,*LPIP_TCP_FRAME;


//UDP数据包头部
typedef  struct tagUDP_HEADER
{
	unsigned   short   sport;           //源端口
	unsigned   short   dport;           //目的端口
	unsigned   short   len;             //Datagram length  标明UDP头部和UDP数据的总长度字节。
	unsigned   short   crc;             //Checksum    校验和 用来对UDP头部和UDP数据进行校验。和TCP不同的是，对UDP来说，此字段是可选项，而TCP数据段中的校验和字段是必须有的。
}UDP_HEADER,*LPUDP_HEADER;

#endif