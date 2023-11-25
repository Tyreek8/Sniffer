#include "mainwindow.h"

#include <QApplication>

/*
 * 这段代码是网络嗅探器的主程序，它创建了一个QApplication对象和一个MainWindow对象，然后显示主窗口并进入事件循环。
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.firstinit();
    w.show();
    return a.exec();
}
