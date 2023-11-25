/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
    QPlainTextEdit *binBrowser_2;
    QPushButton *aboutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1264, 766);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/pic/resource/sniffer.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action111 = new QAction(MainWindow);
        action111->setObjectName(QString::fromUtf8("action111"));
        action111_2 = new QAction(MainWindow);
        action111_2->setObjectName(QString::fromUtf8("action111_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nalabel = new QLabel(centralwidget);
        nalabel->setObjectName(QString::fromUtf8("nalabel"));
        nalabel->setGeometry(QRect(52, 30, 81, 31));
        nalabel->setMaximumSize(QSize(10000, 10000));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        nalabel->setFont(font);
        filterlabel = new QLabel(centralwidget);
        filterlabel->setObjectName(QString::fromUtf8("filterlabel"));
        filterlabel->setGeometry(QRect(940, 30, 81, 31));
        filterlabel->setMaximumSize(QSize(10000, 10000));
        filterlabel->setFont(font);
        naBox = new QComboBox(centralwidget);
        naBox->setObjectName(QString::fromUtf8("naBox"));
        naBox->setGeometry(QRect(140, 30, 711, 31));
        naBox->setMaximumSize(QSize(16777215, 10000));
        filterBox = new QComboBox(centralwidget);
        filterBox->setObjectName(QString::fromUtf8("filterBox"));
        filterBox->setGeometry(QRect(1030, 30, 181, 31));
        filterBox->setMaximumSize(QSize(10000, 10000));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(950, 120, 111, 61));
        startButton->setFont(font);
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1100, 120, 101, 61));
        stopButton->setFont(font);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(950, 220, 111, 61));
        exitButton->setFont(font);
        allPktView = new QTableWidget(centralwidget);
        allPktView->setObjectName(QString::fromUtf8("allPktView"));
        allPktView->setGeometry(QRect(50, 90, 801, 241));
        binBrowser = new QPlainTextEdit(centralwidget);
        binBrowser->setObjectName(QString::fromUtf8("binBrowser"));
        binBrowser->setGeometry(QRect(50, 530, 581, 181));
        binBrowser->setReadOnly(true);
        pktDetails = new QTreeWidget(centralwidget);
        pktDetails->setObjectName(QString::fromUtf8("pktDetails"));
        pktDetails->setGeometry(QRect(50, 340, 1171, 181));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(650, 530, 571, 181));
        groupBox->setFont(font);
        ip4label = new QLabel(groupBox);
        ip4label->setObjectName(QString::fromUtf8("ip4label"));
        ip4label->setGeometry(QRect(80, 20, 61, 31));
        ip4lineEdit = new QLineEdit(groupBox);
        ip4lineEdit->setObjectName(QString::fromUtf8("ip4lineEdit"));
        ip4lineEdit->setGeometry(QRect(140, 20, 111, 31));
        ip4lineEdit->setReadOnly(true);
        ip6lineEdit = new QLineEdit(groupBox);
        ip6lineEdit->setObjectName(QString::fromUtf8("ip6lineEdit"));
        ip6lineEdit->setGeometry(QRect(400, 20, 111, 31));
        ip6lineEdit->setReadOnly(true);
        ip6label = new QLabel(groupBox);
        ip6label->setObjectName(QString::fromUtf8("ip6label"));
        ip6label->setGeometry(QRect(340, 20, 61, 31));
        arplineEdit = new QLineEdit(groupBox);
        arplineEdit->setObjectName(QString::fromUtf8("arplineEdit"));
        arplineEdit->setGeometry(QRect(140, 60, 111, 31));
        arplineEdit->setReadOnly(true);
        arplabel = new QLabel(groupBox);
        arplabel->setObjectName(QString::fromUtf8("arplabel"));
        arplabel->setGeometry(QRect(80, 60, 61, 31));
        tcplineEdit = new QLineEdit(groupBox);
        tcplineEdit->setObjectName(QString::fromUtf8("tcplineEdit"));
        tcplineEdit->setGeometry(QRect(400, 60, 111, 31));
        tcplineEdit->setReadOnly(true);
        tcplabel = new QLabel(groupBox);
        tcplabel->setObjectName(QString::fromUtf8("tcplabel"));
        tcplabel->setGeometry(QRect(340, 60, 61, 31));
        udplineEdit = new QLineEdit(groupBox);
        udplineEdit->setObjectName(QString::fromUtf8("udplineEdit"));
        udplineEdit->setGeometry(QRect(140, 100, 111, 31));
        udplineEdit->setReadOnly(true);
        udplabel = new QLabel(groupBox);
        udplabel->setObjectName(QString::fromUtf8("udplabel"));
        udplabel->setGeometry(QRect(80, 100, 61, 31));
        icmplineEdit = new QLineEdit(groupBox);
        icmplineEdit->setObjectName(QString::fromUtf8("icmplineEdit"));
        icmplineEdit->setGeometry(QRect(400, 100, 111, 31));
        icmplineEdit->setReadOnly(true);
        icmplabel = new QLabel(groupBox);
        icmplabel->setObjectName(QString::fromUtf8("icmplabel"));
        icmplabel->setGeometry(QRect(340, 100, 61, 31));
        httplineEdit = new QLineEdit(groupBox);
        httplineEdit->setObjectName(QString::fromUtf8("httplineEdit"));
        httplineEdit->setGeometry(QRect(140, 140, 111, 31));
        httplineEdit->setReadOnly(true);
        httplabel = new QLabel(groupBox);
        httplabel->setObjectName(QString::fromUtf8("httplabel"));
        httplabel->setGeometry(QRect(80, 140, 61, 31));
        otherlineEdit = new QLineEdit(groupBox);
        otherlineEdit->setObjectName(QString::fromUtf8("otherlineEdit"));
        otherlineEdit->setGeometry(QRect(400, 140, 111, 31));
        otherlineEdit->setReadOnly(true);
        otherlabel = new QLabel(groupBox);
        otherlabel->setObjectName(QString::fromUtf8("otherlabel"));
        otherlabel->setGeometry(QRect(340, 140, 61, 31));
        binBrowser_2 = new QPlainTextEdit(groupBox);
        binBrowser_2->setObjectName(QString::fromUtf8("binBrowser_2"));
        binBrowser_2->setGeometry(QRect(0, 0, 571, 181));
        binBrowser_2->setReadOnly(true);
        binBrowser_2->raise();
        ip4label->raise();
        ip4lineEdit->raise();
        ip6lineEdit->raise();
        ip6label->raise();
        arplineEdit->raise();
        arplabel->raise();
        tcplineEdit->raise();
        tcplabel->raise();
        udplineEdit->raise();
        udplabel->raise();
        icmplineEdit->raise();
        icmplabel->raise();
        httplineEdit->raise();
        httplabel->raise();
        otherlineEdit->raise();
        otherlabel->raise();
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(1100, 220, 101, 61));
        aboutButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        nalabel->raise();
        filterlabel->raise();
        naBox->raise();
        filterBox->raise();
        startButton->raise();
        stopButton->raise();
        exitButton->raise();
        allPktView->raise();
        binBrowser->raise();
        pktDetails->raise();
        aboutButton->raise();
        groupBox->raise();
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\275\221\347\273\234\345\227\205\346\216\242\345\231\250 Sniffer", nullptr));
        action111->setText(QApplication::translate("MainWindow", "111", nullptr));
        action111_2->setText(QApplication::translate("MainWindow", "111", nullptr));
        nalabel->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\275\221\345\215\241\357\274\232", nullptr));
        filterlabel->setText(QApplication::translate("MainWindow", "\346\214\211\345\215\217\350\256\256\350\277\207\346\273\244\357\274\232", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\215\225\350\216\267\357\274\201", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234\344\270\200\344\270\213~", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "> \347\202\271\346\210\221\351\200\200\345\207\272 <", nullptr));
        binBrowser->setPlainText(QString());
        QTreeWidgetItem *___qtreewidgetitem = pktDetails->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\345\214\205\350\257\246\346\203\205", nullptr));
        groupBox->setTitle(QString());
        ip4label->setText(QApplication::translate("MainWindow", "IPv4\357\274\232", nullptr));
        ip6label->setText(QApplication::translate("MainWindow", "IPv6\357\274\232", nullptr));
        arplabel->setText(QApplication::translate("MainWindow", "ARP\357\274\232", nullptr));
        tcplabel->setText(QApplication::translate("MainWindow", "TCP\357\274\232", nullptr));
        udplabel->setText(QApplication::translate("MainWindow", "UDP\357\274\232", nullptr));
        icmplabel->setText(QApplication::translate("MainWindow", "ICMP\357\274\232", nullptr));
        httplabel->setText(QApplication::translate("MainWindow", "HTTP\357\274\232", nullptr));
        otherlabel->setText(QApplication::translate("MainWindow", "\345\205\266\344\273\226\357\274\232", nullptr));
        binBrowser_2->setPlainText(QApplication::translate("MainWindow", "\346\215\225\350\216\267\347\232\204\345\220\204\345\215\217\350\256\256\345\214\205\347\232\204\346\225\260\351\207\217", nullptr));
        aboutButton->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\344\275\234\350\200\205 ^o^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
