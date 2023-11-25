#ifndef CAPTHREAD_H
#define CAPTHREAD_H

#include <QThread>
#include <QMainWindow>
#include <QVector>
#include "datastruct.h"

#define WPCAP
#define HAVA_REMOTE

#include "pcap.h"

#ifndef WIN32
    #include <sys/socket.h>
    #include <netinet/in.h>
#else
    #include <ws2tcpip.h>
    #include <winsock2.h>
#endif

/*
 * 这段代码定义了一个名为CapThread的类，该类继承自QThread，用于在Qt5中创建一个新的线程，这个类被设计用来捕获网络数据包
 * 这个类是网络嗅探器的核心部分，负责捕获和处理网络数据包
 */

class CapThread : public QThread {

    Q_OBJECT

public:
    //通过构造函数从main获得

    pcap_if_t *alldevs; //这是一个指向所有网络设备的指针
    QMainWindow *w; //这是一个指向主窗口的指针
    int selectNaIndex;  //表示用户选择的网络适配器的索引
    QString selectfilter;   //表示用户选择的过滤规则

    pcap_if_t *d;   //这是一个指向用户选择的设备的指针
    char errbuf[PCAP_ERRBUF_SIZE];  //这是一个字符数组，用于存储错误信息
    pcap_t *adhandle;   //这是一个指向数据包捕获描述符的指针
    u_int netmask;  //此无符号整数表示网络掩码
    struct bpf_program fcode;   //此结构体表示过滤规则
    struct pcap_pkthdr *header; //这是一个指向数据包头的指针
    const u_char *pkt_data; //该整数数组用于存储各种类型的数据包的数量
    int pktCount[8];    //该布尔值表示是否停止捕获

    bool stopCapture;

    //这是类的构造函数，用于初始化类的成员变量
    CapThread(QMainWindow *w, pcap_if_t *alldevs, int selectNaIndex, QString selectfilter);
    //这是类的析构函数，用于清理类的成员变量
    ~CapThread();
    //这是类的主要方法，用于开始捕获数据包
    void run();

    //用于检查以太网头
    bool checkEth();
    //用于获取网络掩码
    u_int getNetmask();
    //用于设置过滤规则
    bool setFilter(QString rule);
    //用于开始捕获数据包
    void startCapture();
signals:
    //当捕获到一个数据包时，这个信号会被触发，并将数据包的信息发送到主窗口这样，主窗口就可以实时显示捕获到的数据包的信息了
    void sendDataToMain(QStringList data_tmp, int rowIndex, const u_char *pkt_data, QStringList pktcount, QStringList datainfo);
};

#endif // CAPTHREAD_H
