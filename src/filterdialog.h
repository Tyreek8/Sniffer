#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

/*
 * 这段代码定义了一个名为FilterDialog的类，该类继承自QDialog，用于在Qt5中创建一个“自定义过滤规则”对话框
 */

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

private:
    Ui::FilterDialog *ui;

signals:
    void sendFilterRule(QString rule);
};

#endif // FILTERDIALOG_H
