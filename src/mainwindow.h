#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WPCAP
#define HAVE_REMOTE

#include <QMainWindow>
#include <datastruct.h>
#include <capThread.h>
#include <QVector>
#include <memory>

#ifndef WIN32
    #include <sys/socket.h>
    #include <netinet/in.h>
#else
    #include <ws2tcpip.h>
    #include <winsock2.h>
#endif

/*
 * 这段代码定义了一个名为MainWindow的类，该类继承自QMainWindow，用于在Qt5中创建一个主窗口
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int selectNaIndex;
    QString selectfilter = "all";
    pcap_if_t *alldevs;
    pcap_if_t *d;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *adhandle;
    u_int netmask;
    struct bpf_program fcode;
    struct pcap_pkthdr *header;
    const u_char *pkt_data;
    int pktCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    QVector<pktData> pktRaw;
    QVector<QStringList> pktVector;

    bool stopCapture;

    CapThread *capThread = nullptr;

    QVector<devInfo> getDevList();
    void firstinit();
    void interfaceAfterStart();
    void interfaceAfterStop();
    void showPktDetails();
    void showPktBin();

private:
    Ui::MainWindow *ui;

    //信号start()和stop()：当用户点击开始和停止按钮时，这些信号会被触发
signals:
    void start();
    void stop();

public slots:
    //槽reciveFilterRule：当用户输入一个过滤规则并点击确定按钮时，这个槽会被调用，用于接收过滤规则
    QString reciveFilterRule(QString rule);
    //槽Start()和Stop()：当start()和stop()信号被触发时，这些槽会被调用，用于开始和停止捕获数据包
    void Start();
    void Stop();
    //槽addToView：当捕获到一个数据包时，这个槽会被调用，用于将数据包的信息添加到视图中。
    void addToView(QStringList data, int rowIndex, const u_char *pkt_data, QStringList pktcount, QStringList datainfo);

};
#endif // MAINWINDOW_H
