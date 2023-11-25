/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action111;
    QAction *action111_2;
    QWidget *centralwidget;
    QLabel *nalabel;
    QLabel *filterlabel;
    QComboBox *naBox;
    QComboBox *filterBox;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *exitButton;
    QTableWidget *allPktView;
    QPlainTextEdit *binBrowser;
    QTreeWidget *pktDetails;
    QGroupBox *groupBox;
    QLabel *ip4label;
    QLineEdit *ip4lineEdit;
    QLineEdit *ip6lineEdit;
    QLabel *ip6label;
    QLineEdit *arplineEdit;
    QLabel *arplabel;
    QLineEdit *tcplineEdit;
    QLabel *tcplabel;
    QLineEdit *udplineEdit;
    QLabel *udplabel;
    QLineEdit *icmplineEdit;
    QLabel *icmplabel;
    QLineEdit *httplineEdit;
    QLabel *httplabel;
    QLineEdit *otherlineEdit;
    QLabel *otherlabel;
    QPushButton *aboutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1264, 766);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/resource/sniffer.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action111 = new QAction(MainWindow);
        action111->setObjectName(QString::fromUtf8("action111"));
        action111_2 = new QAction(MainWindow);
        action111_2->setObjectName(QString::fromUtf8("action111_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nalabel = new QLabel(centralwidget);
        nalabel->setObjectName(QString::fromUtf8("nalabel"));
        nalabel->setGeometry(QRect(41, 15, 81, 31));
        nalabel->setMaximumSize(QSize(10000, 10000));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        nalabel->setFont(font);
        filterlabel = new QLabel(centralwidget);
        filterlabel->setObjectName(QString::fromUtf8("filterlabel"));
        filterlabel->setGeometry(QRect(40, 50, 81, 31));
        filterlabel->setMaximumSize(QSize(10000, 10000));
        filterlabel->setFont(font);
        naBox = new QComboBox(centralwidget);
        naBox->setObjectName(QString::fromUtf8("naBox"));
        naBox->setGeometry(QRect(129, 15, 511, 31));
        naBox->setMaximumSize(QSize(16777215, 10000));
        filterBox = new QComboBox(centralwidget);
        filterBox->setObjectName(QString::fromUtf8("filterBox"));
        filterBox->setGeometry(QRect(130, 50, 171, 31));
        filterBox->setMaximumSize(QSize(10000, 10000));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(690, 20, 91, 51));
        startButton->setFont(font);
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(830, 20, 91, 51));
        stopButton->setFont(font);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(970, 20, 91, 51));
        exitButton->setFont(font);
        allPktView = new QTableWidget(centralwidget);
        allPktView->setObjectName(QString::fromUtf8("allPktView"));
        allPktView->setGeometry(QRect(30, 90, 1201, 241));
        binBrowser = new QPlainTextEdit(centralwidget);
        binBrowser->setObjectName(QString::fromUtf8("binBrowser"));
        binBrowser->setGeometry(QRect(30, 530, 571, 181));
        pktDetails = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        pktDetails->setHeaderItem(__qtreewidgetitem);
        pktDetails->setObjectName(QString::fromUtf8("pktDetails"));
        pktDetails->setGeometry(QRect(30, 340, 1201, 181));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(630, 530, 601, 181));
        groupBox->setFont(font);
        ip4label = new QLabel(groupBox);
        ip4label->setObjectName(QString::fromUtf8("ip4label"));
        ip4label->setGeometry(QRect(60, 20, 61, 31));
        ip4lineEdit = new QLineEdit(groupBox);
        ip4lineEdit->setObjectName(QString::fromUtf8("ip4lineEdit"));
        ip4lineEdit->setGeometry(QRect(120, 20, 111, 31));
        ip6lineEdit = new QLineEdit(groupBox);
        ip6lineEdit->setObjectName(QString::fromUtf8("ip6lineEdit"));
        ip6lineEdit->setGeometry(QRect(430, 20, 111, 31));
        ip6label = new QLabel(groupBox);
        ip6label->setObjectName(QString::fromUtf8("ip6label"));
        ip6label->setGeometry(QRect(370, 20, 61, 31));
        arplineEdit = new QLineEdit(groupBox);
        arplineEdit->setObjectName(QString::fromUtf8("arplineEdit"));
        arplineEdit->setGeometry(QRect(120, 60, 111, 31));
        arplabel = new QLabel(groupBox);
        arplabel->setObjectName(QString::fromUtf8("arplabel"));
        arplabel->setGeometry(QRect(60, 60, 61, 31));
        tcplineEdit = new QLineEdit(groupBox);
        tcplineEdit->setObjectName(QString::fromUtf8("tcplineEdit"));
        tcplineEdit->setGeometry(QRect(430, 60, 111, 31));
        tcplabel = new QLabel(groupBox);
        tcplabel->setObjectName(QString::fromUtf8("tcplabel"));
        tcplabel->setGeometry(QRect(370, 60, 61, 31));
        udplineEdit = new QLineEdit(groupBox);
        udplineEdit->setObjectName(QString::fromUtf8("udplineEdit"));
        udplineEdit->setGeometry(QRect(120, 100, 111, 31));
        udplabel = new QLabel(groupBox);
        udplabel->setObjectName(QString::fromUtf8("udplabel"));
        udplabel->setGeometry(QRect(60, 100, 61, 31));
        icmplineEdit = new QLineEdit(groupBox);
        icmplineEdit->setObjectName(QString::fromUtf8("icmplineEdit"));
        icmplineEdit->setGeometry(QRect(430, 100, 111, 31));
        icmplabel = new QLabel(groupBox);
        icmplabel->setObjectName(QString::fromUtf8("icmplabel"));
        icmplabel->setGeometry(QRect(370, 100, 61, 31));
        httplineEdit = new QLineEdit(groupBox);
        httplineEdit->setObjectName(QString::fromUtf8("httplineEdit"));
        httplineEdit->setGeometry(QRect(120, 140, 111, 31));
        httplabel = new QLabel(groupBox);
        httplabel->setObjectName(QString::fromUtf8("httplabel"));
        httplabel->setGeometry(QRect(60, 140, 61, 31));
        otherlineEdit = new QLineEdit(groupBox);
        otherlineEdit->setObjectName(QString::fromUtf8("otherlineEdit"));
        otherlineEdit->setGeometry(QRect(430, 140, 111, 31));
        otherlabel = new QLabel(groupBox);
        otherlabel->setObjectName(QString::fromUtf8("otherlabel"));
        otherlabel->setGeometry(QRect(370, 140, 61, 31));
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(1110, 20, 91, 51));
        aboutButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1264, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(exitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "sniffer", nullptr));
        action111->setText(QCoreApplication::translate("MainWindow", "111", nullptr));
        action111_2->setText(QCoreApplication::translate("MainWindow", "111", nullptr));
        nalabel->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\275\221\345\215\241\357\274\232", nullptr));
        filterlabel->setText(QCoreApplication::translate("MainWindow", "\350\277\207\346\273\244\350\247\204\345\210\231\357\274\232", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "static", nullptr));
        ip4label->setText(QCoreApplication::translate("MainWindow", "IPv4\357\274\232", nullptr));
        ip6label->setText(QCoreApplication::translate("MainWindow", "IPv6\357\274\232", nullptr));
        arplabel->setText(QCoreApplication::translate("MainWindow", "ARP\357\274\232", nullptr));
        tcplabel->setText(QCoreApplication::translate("MainWindow", "TCP\357\274\232", nullptr));
        udplabel->setText(QCoreApplication::translate("MainWindow", "UDP\357\274\232", nullptr));
        icmplabel->setText(QCoreApplication::translate("MainWindow", "ICMP\357\274\232", nullptr));
        httplabel->setText(QCoreApplication::translate("MainWindow", "HTTP\357\274\232", nullptr));
        otherlabel->setText(QCoreApplication::translate("MainWindow", "\345\205\266\344\273\226\357\274\232", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
