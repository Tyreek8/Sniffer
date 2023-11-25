#include "about.h"
#include "ui_about.h"

/*
 * 这段代码定义了一个名为About的类，该类继承自QDialog，用于在Qt5中创建一个“关于”对话框
 */

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}
