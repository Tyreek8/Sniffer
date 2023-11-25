/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QLineEdit *filterlineEdit;
    QLabel *label;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(400, 300);
        FilterDialog->setStyleSheet(QString::fromUtf8(""));
        filterlineEdit = new QLineEdit(FilterDialog);
        filterlineEdit->setObjectName(QString::fromUtf8("filterlineEdit"));
        filterlineEdit->setGeometry(QRect(20, 130, 351, 31));
        label = new QLabel(FilterDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        label->setFont(font);
        okButton = new QPushButton(FilterDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(50, 230, 93, 41));
        okButton->setFont(font);
        okButton->setStyleSheet(QString::fromUtf8(""));
        cancelButton = new QPushButton(FilterDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 230, 93, 41));
        cancelButton->setFont(font);
        cancelButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(FilterDialog);

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QApplication::translate("FilterDialog", "\350\207\252\345\256\232\344\271\211\350\277\207\346\273\244\350\247\204\345\210\231", nullptr));
        label->setText(QApplication::translate("FilterDialog", "\350\276\223\345\205\245\350\277\207\346\273\244\350\247\204\345\210\231\357\274\232", nullptr));
        okButton->setText(QApplication::translate("FilterDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("FilterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
