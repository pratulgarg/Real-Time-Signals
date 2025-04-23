/********************************************************************************
** Form generated from reading UI file 'forgotPassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORD_H
#define UI_FORGOTPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_forgotPassword
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QPushButton *pushButton_changePassword;

    void setupUi(QDialog *forgotPassword)
    {
        if (forgotPassword->objectName().isEmpty())
            forgotPassword->setObjectName(QString::fromUtf8("forgotPassword"));
        forgotPassword->resize(1127, 649);
        groupBox = new QGroupBox(forgotPassword);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 60, 291, 321));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 111, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 141, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 80, 271, 31));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 150, 271, 31));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(10, 220, 271, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 200, 141, 21));
        pushButton_changePassword = new QPushButton(groupBox);
        pushButton_changePassword->setObjectName(QString::fromUtf8("pushButton_changePassword"));
        pushButton_changePassword->setGeometry(QRect(50, 270, 171, 41));
        pushButton_changePassword->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  /* No border by default */\n"
"    background-color: transparent;  /* Transparent background */\n"
"    color: black;  /* Black text color */\n"
"    padding: 5px 10px;  /* Padding for the button */\n"
"    font-size: 16px;  /* Font size */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: white;  /* White background on hover */\n"
"    color: black;  /* Keep text black */\n"
"    border: 1px solid black;  /* Optional border when hovered */\n"
"}\n"
""));

        retranslateUi(forgotPassword);

        QMetaObject::connectSlotsByName(forgotPassword);
    } // setupUi

    void retranslateUi(QDialog *forgotPassword)
    {
        forgotPassword->setWindowTitle(QApplication::translate("forgotPassword", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("forgotPassword", "Forgot Password", nullptr));
        label->setText(QApplication::translate("forgotPassword", "Enter Username", nullptr));
        label_2->setText(QApplication::translate("forgotPassword", "Email", nullptr));
        label_5->setText(QApplication::translate("forgotPassword", "Change Password", nullptr));
        pushButton_changePassword->setText(QApplication::translate("forgotPassword", "Change Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgotPassword: public Ui_forgotPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H
