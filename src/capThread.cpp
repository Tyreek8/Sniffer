#include "capThread.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QByteArray>

/*
 * 这段代码定义了一个名为CapThread的类，该类继承自QThread，用于在Qt5中创建一个新的线程，这个类被设计用来捕获网络数据包
 * 这个类是网络嗅探器的核心部分，负责捕获和处理网络数据包
 */

CapThread::CapThread(QMainWindow *w, pcap_if_t *alldevs, int selectNaIndex, QString selectfilter) {
    this->alldevs = alldevs;
    this->w = w;
    this->selectNaIndex = selectNaIndex;
    this->selectfilter = selectfilter;
    memset(pktCount, 0, sizeof(pktCount));
}

CapThread::~CapThread(){
    pcap_close(adhandle);

    requestInterruption();
    quit();
    wait();
}

void CapThread::run() {
    stopCapture = false;

    //打开指定网卡，设置过滤条件，并抓包
    d = alldevs;
    for(int i = 0; i < selectNaIndex; i++){
        d = d->next;
    }

    if((adhandle = pcap_open_live(d->name,
                             65536,
                             1,
                             1000,
                             errbuf)) == NULL) {
    }

    //检查是否是以太网
//    if(checkEth() == false) {
//        //ui->binBrowser->clear();
//        //ui->binBrowser->setText("not support this network adapter");
//    }

    //获取netmask(设置过滤条件时需要)
    netmask = getNetmask();

    //设置过滤条件
    if(setFilter(selectfilter) == false) {
        return;
    } else {
        //开始抓包
        startCapture();

        //抓包后释放网卡
        //pcap_freealldevs(alldevs);
    }
}

bool CapThread::checkEth() {
    if(pcap_datalink(this->adhandle) != DLT_EN10MB){
        return false;
    }
    return true;
}

u_int CapThread::getNetmask() {
    u_int netmask;
    if(d->addresses != NULL) {
        netmask = ((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    } else {
        netmask = 0xffffff;
    }
    return netmask;
}

bool CapThread::setFilter(QString rule) {
    if(rule == "all") return true;
    char *Rule;
    QByteArray ba = rule.toLatin1();
    Rule = ba.data();
    if(pcap_compile(adhandle, &fcode, Rule, 1, netmask) < 0 ) {
        return false;
    }
    if(pcap_setfilter(adhandle, &fcode) < 0) {
        return false;
    }
    return true;
}

//实现将MAC地址中的10进制数转16进制
QString decimalToHex(const QString& decimalStr) {
    bool ok;
    int decimal = decimalStr.toInt(&ok);
    if (!ok) {
        // 处理无效的十进制数输入
        return QString();
    }

    QString hexadecimal = QString::number(decimal, 16).toUpper();

    // 如果转换后的十六进制数少于2位，则在前面补一个前导0
    if (hexadecimal.length() < 2) {
        hexadecimal.prepend('0');
    }

    return hexadecimal;
}

void CapThread::startCapture() {
    int res;
    int rowIndex = 0;
    while((res = pcap_next_ex(adhandle, &header, &pkt_data)) >= 0) {
        if(res == 0) continue;

        QString data[7];
        QStringList datainfo;

        struct tm ltime;
        char timestr[16];

        ethHeader *eh = (ethHeader *)pkt_data;
        QString tmp="源MAC地址： ";
        for(int i = 0; i < 6; i++) {
            tmp += decimalToHex(QString::number(eh->src_addr[i]));
            if(i != 5)tmp = tmp + ":";
        }
        datainfo<<tmp;
        QString srcMac = tmp;
        tmp.clear();
        tmp="目的MAC地址： ";
        for(int i = 0; i < 6; i++) {
            tmp += decimalToHex(QString::number(eh->dest_addr[i]));
            if(i != 5)tmp = tmp + ":";
        }
        datainfo<<tmp;
        QString destMac = tmp;

        ipHeader *ih;
        ipv6Header *iv6h;
        arpHeader *ah;
        tcpHeader *th;
        udpHeader *uh;
        icmpHeader *icmph;

        u_int iph_len;
        u_int ipv6_len;
        u_int arp_len;
        u_short sport, dport;

        time_t local_tv_sec;

        local_tv_sec = header->ts.tv_sec;
        localtime_s(&ltime, &local_tv_sec);
        strftime(timestr, sizeof timestr, "%H:%M:%S", &ltime);
        data[0] = timestr;
        data[1] = QString::number(header->len);

        ih = (ipHeader *)(pkt_data + 14);
        iv6h = (ipv6Header *)(pkt_data + 14);
        ah = (arpHeader *)(pkt_data + 14);

        //ipv4
        if(ntohs(eh->type) == 2048) {
            pktCount[0]++;
            datainfo<<"IPv4";
            datainfo<<"IPv4";

            // 首部长度指的是首部占32bit字的数目
            data[3] = QString::number(ih->src_addr[0]) + "." +
                    QString::number(ih->src_addr[1]) + "." +
                    QString::number(ih->src_addr[2]) + "." +
                    QString::number(ih->src_addr[3]);
            data[4] = QString::number(ih->dest_addr[0]) + "." +
                    QString::number(ih->dest_addr[1]) + "." +
                    QString::number(ih->dest_addr[2]) + "." +
                    QString::number(ih->dest_addr[3]);
            //根据ip报文首部的protocol域确定下一首部隶属于哪个协议
            iph_len = (ih->ver_ihl & 0xf) * 4;
            datainfo.append("首部长： "+QString::number(iph_len));
            datainfo.append("服务类型： "+QString::number(ih->tos));
            datainfo.append("包长度的字节数： "+QString::number(ih->tlen));
            datainfo.append("表示符： "+QString::number(ih->identification));
            datainfo.append("标记位： "+QString::number(ih->flag_fo & 0xe000));
            datainfo.append("片偏移： "+QString::number(ih->flag_fo & 0x1fff));
            datainfo.append("生存期： "+QString::number(ih->ttl));

            uh = (udpHeader *)(pkt_data + iph_len);
            th = (tcpHeader *)(pkt_data + iph_len);
            icmph = (icmpHeader *)(pkt_data + iph_len);
            if(ih->proto == 6) {
                pktCount[3]++;
                datainfo<<"TCP";
                datainfo.append("CRC校验: "+QString::number(ih->crc));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                datainfo.append("可选项和填充: "+QString::number(ih->op_pad));
                data[2] = "TCP";
                sport = ntohs(th->src_port);
                dport = ntohs(th->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("序列号: "+QString::number(th->seq));
                datainfo.append("确认号: "+QString::number(th->ack));
                datainfo.append("TCP首部长度(数据偏移): "+QString::number(th->hl_flag & 0xf000));
                datainfo.append("紧急URG: "+QString::number(th->hl_flag & 0x0020));
                datainfo.append("确认ACK: "+QString::number(th->hl_flag & 0x0010));
                datainfo.append("推送PSH: "+QString::number(th->hl_flag & 0x0008));
                datainfo.append("复位RST: "+QString::number(th->hl_flag & 0x0004));
                datainfo.append("同步SYN: "+QString::number(th->hl_flag & 0x0002));
                datainfo.append("终止FIN: "+QString::number(th->hl_flag & 0x0001));
                datainfo.append("窗口大小: "+QString::number(th->windowsize));
                datainfo.append("检验和: "+QString::number(th->checksum));
                datainfo.append("紧急数据偏移量: "+QString::number(th->urgpoint));
                datainfo.append("可选字段: "+QString::number(th->ops));
            } else if(ih->proto == 17) {
                pktCount[4]++;
                data[2] = "UDP";
                datainfo<<"UDP";
                datainfo.append("CRC校验: "+QString::number(ih->crc));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                datainfo.append("可选项和填充: "+QString::number(ih->op_pad));
                sport = ntohs(uh->src_port);
                dport = ntohs(uh->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("udp用户数据报（首部+数据部分）的字节数: "+QString::number(uh->udplen));
                datainfo.append("检验和: "+QString::number(uh->checksum));
                datainfo.append("数据部分: "+QString::number(uh->data));

            } else if(ih->proto == 1){
                pktCount[5]++;
                data[2] = "ICMP";
                datainfo<<"ICMP";
                datainfo.append("CRC校验: "+QString::number(ih->crc));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                datainfo.append("可选项和填充: "+QString::number(ih->op_pad));
                data[5] = "Other";
                data[6] = "Other";
                datainfo.append("ICMP报文的类型: "+QString::number(icmph->type));
                datainfo.append("ICMP报文的代码: "+QString::number(icmph->code));
                datainfo.append("检验和: "+QString::number(icmph->checksum));
                datainfo.append("标识符: "+QString::number(icmph->id));
                datainfo.append("ICMP报文的序号: "+QString::number(icmph->seq));
            } else {
                pktCount[7]++;
                datainfo<<"Other";
                datainfo<<"ICMP";
                datainfo.append("CRC校验: "+QString::number(ih->crc));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                datainfo.append("可选项和填充: "+QString::number(ih->op_pad));
                data[2] = "Other";
                data[5] = "Other";
                data[6] = "Other";
            }
        } else if(ntohs(eh->type) == 34525) { // ipv6
            pktCount[1]++;
            datainfo<<"IPv6";
            datainfo<<"IPv6";
            datainfo.append("流类型: "+QString::number(iv6h->flowtype));
            datainfo.append("流标签: "+QString::number(iv6h->flowid));
            datainfo.append("有效载荷长度: "+QString::number(iv6h->plen));

            QString src = "";
            for(int i = 0; i < 8; i++) {
                src = src + QString::number(iv6h->src_addr[i]);
                if(i != 7)src = src + ".";
            }
            data[3] = src;
            QString dest = "";
            for(int i = 0; i < 8; i++) {
                dest = dest + QString::number(iv6h->dest_addr[i]);
                if(i != 7)dest = dest + ".";
            }
            data[4] = dest;

            ipv6_len = iv6h->plen;
            uh = (udpHeader *)(pkt_data + ipv6_len);
            th = (tcpHeader *)(pkt_data + ipv6_len);
            icmph = (icmpHeader *)(pkt_data + ipv6_len);
            if(iv6h->nh == 6) {
                pktCount[3]++;
                data[2] = "TCP";
                datainfo<<"TCP";
                datainfo.append("跳限制: "+QString::number(iv6h->hlim));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);

                sport = ntohs(th->src_port);
                dport = ntohs(th->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("序列号: "+QString::number(th->seq));
                datainfo.append("确认号: "+QString::number(th->ack));
                datainfo.append("TCP首部长度(数据偏移): "+QString::number(th->hl_flag & 0xf000));
                datainfo.append("紧急URG: "+QString::number(th->hl_flag & 0x0020));
                datainfo.append("确认ACK: "+QString::number(th->hl_flag & 0x0010));
                datainfo.append("推送PSH: "+QString::number(th->hl_flag & 0x0008));
                datainfo.append("复位RST: "+QString::number(th->hl_flag & 0x0004));
                datainfo.append("同步SYN: "+QString::number(th->hl_flag & 0x0002));
                datainfo.append("终止FIN: "+QString::number(th->hl_flag & 0x0001));
                datainfo.append("窗口大小: "+QString::number(th->windowsize));
                datainfo.append("检验和: "+QString::number(th->checksum));
                datainfo.append("紧急数据偏移量: "+QString::number(th->urgpoint));
                datainfo.append("可选字段: "+QString::number(th->ops));

            } else if(iv6h->nh == 17) {
                pktCount[4]++;
                data[2] = "UDP";
                datainfo<<"UDP";
                datainfo.append("跳限制: "+QString::number(iv6h->hlim));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);

                sport = ntohs(uh->src_port);
                dport = ntohs(uh->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("udp用户数据报（首部+数据部分）的字节数: "+QString::number(uh->udplen));
                datainfo.append("检验和: "+QString::number(uh->checksum));
                datainfo.append("数据部分: "+QString::number(uh->data));

            } else if(iv6h->nh == 1){
                pktCount[5]++;
                datainfo<<"ICMP";
                datainfo.append("跳限制: "+QString::number(iv6h->hlim));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                data[2] = "ICMP";
                data[5] = "Other";
                data[6] = "Other";

                datainfo.append("ICMP报文的类型: "+QString::number(icmph->type));
                datainfo.append("ICMP报文的代码: "+QString::number(icmph->code));
                datainfo.append("检验和: "+QString::number(icmph->checksum));
                datainfo.append("标识符: "+QString::number(icmph->id));
                datainfo.append("ICMP报文的序号: "+QString::number(icmph->seq));
            } else {
                pktCount[7]++;
                datainfo<<"Other";
                datainfo.append("跳限制: "+QString::number(iv6h->hlim));
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的IP地址: "+data[4]);
                data[2] = "Other";
                data[5] = "Other";
                data[6] = "Other";
            }

        } else if(ntohs(eh->type) == 2054) { // arp
            pktCount[2]++;
            datainfo<<"ARP";
            datainfo.append("硬件类型: "+QString::number(ah->ar_hw));

            data[3] = QString::number(ah->ar_srcip[0]) + "." +
                    QString::number(ah->ar_srcip[1]) + "." +
                    QString::number(ah->ar_srcip[2]) + "." +
                    QString::number(ah->ar_srcip[3]);
            data[4] = QString::number(ah->ar_destip[0]) + "." +
                    QString::number(ah->ar_destip[1]) + "." +
                    QString::number(ah->ar_destip[2]) + "." +
                    QString::number(ah->ar_destip[3]);

            arp_len = 7 * 4;
            uh = (udpHeader *)(pkt_data + arp_len);
            th = (tcpHeader *)(pkt_data + arp_len);
            icmph = (icmpHeader *)(pkt_data + arp_len);
            if(ah->ar_port == 6) {
                pktCount[3]++;
                data[2] = "TCP";
                datainfo<<"TCP";
                datainfo.append("硬件类型: "+QString::number(ah->ar_hln));
                datainfo.append("硬件(MAC)地址字节数: "+QString::number(ah->ar_pln));
                datainfo.append("协议（IP）地址字节数: "+QString::number(ah->ar_op));
                datainfo.append("源MAC地址: "+srcMac);
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的MAC地址: "+destMac);
                datainfo.append("目的IP地址: "+data[4]);

                sport = ntohs(th->src_port);
                dport = ntohs(th->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("序列号: "+QString::number(th->seq));
                datainfo.append("确认号: "+QString::number(th->ack));
                datainfo.append("TCP首部长度(数据偏移): "+QString::number(th->hl_flag & 0xf000));
                datainfo.append("紧急URG: "+QString::number(th->hl_flag & 0x0020));
                datainfo.append("确认ACK: "+QString::number(th->hl_flag & 0x0010));
                datainfo.append("推送PSH: "+QString::number(th->hl_flag & 0x0008));
                datainfo.append("复位RST: "+QString::number(th->hl_flag & 0x0004));
                datainfo.append("同步SYN: "+QString::number(th->hl_flag & 0x0002));
                datainfo.append("终止FIN: "+QString::number(th->hl_flag & 0x0001));
                datainfo.append("窗口大小: "+QString::number(th->windowsize));
                datainfo.append("检验和: "+QString::number(th->checksum));
                datainfo.append("紧急数据偏移量: "+QString::number(th->urgpoint));
                datainfo.append("可选字段: "+QString::number(th->ops));
            } else if(ah->ar_port == 17) {
                pktCount[4]++;
                data[2] = "UDP";
                datainfo<<"UDP";
                datainfo.append("硬件类型: "+QString::number(ah->ar_hln));
                datainfo.append("硬件(MAC)地址字节数: "+QString::number(ah->ar_pln));
                datainfo.append("协议（IP）地址字节数: "+QString::number(ah->ar_op));
                datainfo.append("源MAC地址: "+srcMac);
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的MAC地址: "+destMac);
                datainfo.append("目的IP地址: "+data[4]);

                sport = ntohs(uh->src_port);
                dport = ntohs(uh->dest_port);
                data[5] = QString::number(sport);
                data[6] = QString::number(dport);

                datainfo.append("源端口号: "+data[5]);
                datainfo.append("目的端口号: "+data[6]);
                datainfo.append("udp用户数据报（首部+数据部分）的字节数: "+QString::number(uh->udplen));
                datainfo.append("检验和: "+QString::number(uh->checksum));
                datainfo.append("数据部分: "+QString::number(uh->data));

            } else if(ah->ar_port == 1){
                pktCount[5]++;
                data[2] = "ICMP";
                datainfo<<"ICMP";
                datainfo.append("硬件类型: "+QString::number(ah->ar_hln));
                datainfo.append("硬件(MAC)地址字节数: "+QString::number(ah->ar_pln));
                datainfo.append("协议（IP）地址字节数: "+QString::number(ah->ar_op));
                datainfo.append("源MAC地址: "+srcMac);
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的MAC地址: "+destMac);
                datainfo.append("目的IP地址: "+data[4]);

                data[5] = "Other";
                data[6] = "Other";
                datainfo.append("ICMP报文的类型: "+QString::number(icmph->type));
                datainfo.append("ICMP报文的代码: "+QString::number(icmph->code));
                datainfo.append("检验和: "+QString::number(icmph->checksum));
                datainfo.append("标识符: "+QString::number(icmph->id));
                datainfo.append("ICMP报文的序号: "+QString::number(icmph->seq));
            } else {
                pktCount[7]++;
                data[2] = "Other";
                datainfo<<"ICMP";
                datainfo.append("硬件类型: "+QString::number(ah->ar_hln));
                datainfo.append("硬件(MAC)地址字节数: "+QString::number(ah->ar_pln));
                datainfo.append("协议（IP）地址字节数: "+QString::number(ah->ar_op));
                datainfo.append("源MAC地址: "+srcMac);
                datainfo.append("源IP地址: "+data[3]);
                datainfo.append("目的MAC地址: "+destMac);
                datainfo.append("目的IP地址: "+data[4]);

                data[5] = "Other";
                data[6] = "Other";
            }
        } else {
            pktCount[7]++;
            datainfo<<"Other";
            for(int i = 2; i < 7; i++) {
                data[i] = "Other";
            }
        }

        QStringList data_tmp;
        for(int k =0; k < 7; k++) {
            data_tmp.append(data[k]);
        }
        QStringList pktcount_tmp;
        for(int k = 0; k < 8; k++) {
            pktcount_tmp.append(QString::number(pktCount[k]));
        }

        emit sendDataToMain(data_tmp, rowIndex, pkt_data, pktcount_tmp, datainfo);
        rowIndex++;
    }
}

