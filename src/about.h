#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

/*
 * 这段代码定义了一个名为About的类，该类继承自QDialog，用于在Qt5中创建一个“关于”对话框
 */

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
