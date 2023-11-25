/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
        cancelButton = new QPushButton(FilterDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 230, 93, 41));
        cancelButton->setFont(font);

        retranslateUi(FilterDialog);

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FilterDialog", "\350\276\223\345\205\245\350\277\207\346\273\244\350\247\204\345\210\231\357\274\232", nullptr));
        okButton->setText(QCoreApplication::translate("FilterDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("FilterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
