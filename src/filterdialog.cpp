#include "filterdialog.h"
#include "ui_filterdialog.h"

/*
 * 这段代码定义了一个名为FilterDialog的类，该类继承自QDialog，用于在Qt5中创建一个“自定义过滤规则”对话框
 */

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, &QPushButton::clicked, [=]() {
        emit sendFilterRule(ui->filterlineEdit->text());
        this->close();
    });
    connect(ui->cancelButton, &QPushButton::clicked, [=]() {
        emit sendFilterRule("");
        this->close();
    });
}

FilterDialog::~FilterDialog()
{
    delete ui;
}
