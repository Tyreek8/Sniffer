#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QString>
#include <QVector>
#include <pcap.h>

//这段代码定义了一系列的数据结构，用于解析网络数据包。每个结构体对应一个网络协议的头部格式

//此结构体包含设备的名称和描述
struct devInfo {
    QString name = "";
    QString description = "";
};

struct ethHeader { //3
    u_char src_addr[6];     //源MAC地址
    u_char dest_addr[6];    //目的MAC地址
    u_short type;       //帧中携带的数据的协议类型
};

struct  ipHeader{ //13
    u_char ver_ihl;     //1个字节，4bit版本、4bit头部长度
    u_char tos;         //1个字节，服务类型（type of service）
    u_short tlen;       //2个字节，ip数据报（首部+数据部分）的字节数
    u_short identification;     //2个字节，表示符
    u_short flag_fo;            //2个字节，3bit标记位、13bit片偏移
    u_char ttl;         //1个字节，生存期
    u_char proto;       //1个字节，协议
    u_short crc;        //2个字节，crc校验
    u_char src_addr[4];     //4个字节，源IP地址
    u_char dest_addr[4];    //4个字节，目的IP地址
    u_int op_pad;       //可选项和填充共计4字节
};

struct ipv6Header { //8
    u_int version:4,				//版本
        flowtype:8,                 //流类型
        flowid:20;                  //流标签
    u_short plen;					//有效载荷长度
    u_char nh;	//7					//下一个头部
    u_char hlim;					//跳限制
    u_short src_addr[8];			//源IP地址
    u_short dest_addr[8];           //目的IP地址
};

struct arpHeader { //9
    u_short ar_hw;						//硬件类型
    u_short ar_port;//4					//协议类型
    u_char ar_hln;						//硬件(MAC)地址字节数
    u_char ar_pln;						//协议（IP）地址字节数
    u_short ar_op;						//操作码，1为请求 2为回复
    u_char ar_srcmac[6];			//源MAC地址
    u_char ar_srcip[4];				//源IP地址
    u_char ar_destmac[6];			//目的MAC地址
    u_char ar_destip[4];            //目的IP地址
};

struct tcpHeader { //15
    u_short src_port;       // 源端口号，2字节
    u_short dest_port;      // 目的端口号，2字节
    u_int seq;      // 序列号，4字节
    u_int ack;      // 确认号，4字节
    u_short hl_flag;    // 前4位：TCP首部长度(数据偏移)；中6位：保留；后6位：标志位
    u_short windowsize;     // 窗口大小，2字节
    u_short checksum;       // 检验和，2字节
    u_short urgpoint;       // 紧急数据偏移量，2字节
    u_int ops;      //可选字段
};


struct udpHeader { //5
    u_short src_port;   //源端口号
    u_short dest_port;  //目的端口号
    u_short udplen;     //udp用户数据报（首部+数据部分）的字节数
    u_short checksum;   //检验和
    u_int data;     //数据部分
};

struct icmpHeader { //5
    u_char type;    //一个8位的无符号字符，表示ICMP报文的类型，用来区分不同的ICMP报文，
                    //比如回显请求（type=8），回显应答（type=0），目的不可达（type=3）等
    u_char code;        //一个8位的无符号字符，表示ICMP报文的代码，用来进一步细化ICMP报文的类型，
                        //比如目的不可达报文中，code=0表示网络不可达，code=1表示主机不可达，code=3表示端口不可达等
    u_short checksum;   //检验和
    u_short id;         //ICMP报文的标识符，用来区分不同的ICMP会话，比如ping命令发送的回显请求报文中，id字段就是ping进程的进程号。
    u_short seq;        //ICMP报文的序号
};

struct pktData {
    int len;
    const u_char *pkt_data;
};

#endif // DATASTRUCT_H
