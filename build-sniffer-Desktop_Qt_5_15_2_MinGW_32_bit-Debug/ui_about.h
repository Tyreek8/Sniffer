/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(400, 411);
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 130, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 200, 91, 41));
        label_2->setFont(font);
        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 60, 221, 151));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/neo.png);"));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "\345\205\263\344\272\216", nullptr));
        label->setText(QCoreApplication::translate("About", "\347\275\221\347\273\234\345\227\205\346\216\242\345\231\250\357\274\232sniffer", nullptr));
        label_2->setText(QCoreApplication::translate("About", "by: swu lty", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
