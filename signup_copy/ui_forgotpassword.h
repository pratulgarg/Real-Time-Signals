/********************************************************************************
** Form generated from reading UI file 'forgotpassword.ui'
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
    QLineEdit *lineEdit_fp1;
    QLabel *label_2;
    QLineEdit *lineEdit_fp2;
    QLabel *label_3;
    QLineEdit *lineEdit_fp3;
    QLineEdit *lineEdit_fp4;
    QLabel *label_4;
    QPushButton *pushButton_change;
    QPushButton *pushButtonBack;

    void setupUi(QDialog *forgotPassword)
    {
        if (forgotPassword->objectName().isEmpty())
            forgotPassword->setObjectName(QString::fromUtf8("forgotPassword"));
        forgotPassword->resize(1153, 626);
        groupBox = new QGroupBox(forgotPassword);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(280, 40, 371, 501));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 211, 31));
        label->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Umpush\";\n"
""));
        lineEdit_fp1 = new QLineEdit(groupBox);
        lineEdit_fp1->setObjectName(QString::fromUtf8("lineEdit_fp1"));
        lineEdit_fp1->setGeometry(QRect(20, 90, 311, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 211, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Umpush\";\n"
""));
        lineEdit_fp2 = new QLineEdit(groupBox);
        lineEdit_fp2->setObjectName(QString::fromUtf8("lineEdit_fp2"));
        lineEdit_fp2->setGeometry(QRect(20, 180, 311, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 240, 211, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Umpush\";\n"
""));
        lineEdit_fp3 = new QLineEdit(groupBox);
        lineEdit_fp3->setObjectName(QString::fromUtf8("lineEdit_fp3"));
        lineEdit_fp3->setGeometry(QRect(20, 270, 311, 41));
        lineEdit_fp4 = new QLineEdit(groupBox);
        lineEdit_fp4->setObjectName(QString::fromUtf8("lineEdit_fp4"));
        lineEdit_fp4->setGeometry(QRect(20, 360, 311, 41));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 330, 211, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Umpush\";\n"
""));
        pushButton_change = new QPushButton(groupBox);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(110, 430, 131, 51));
        pushButton_change->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Ubuntu Condensed\";"));
        pushButtonBack = new QPushButton(groupBox);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(300, 470, 89, 25));
        pushButtonBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none; /* Removes the border */\n"
"    background-color: transparent; /* Transparent background */\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: transparent; /* Keeps background transparent on hover */\n"
"    color: blue; /* Changes text color to blue on hover */\n"
"}\n"
"font: 75 12pt \"Waree\";"));

        retranslateUi(forgotPassword);

        QMetaObject::connectSlotsByName(forgotPassword);
    } // setupUi

    void retranslateUi(QDialog *forgotPassword)
    {
        forgotPassword->setWindowTitle(QApplication::translate("forgotPassword", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("forgotPassword", "Forgot Password", nullptr));
        label->setText(QApplication::translate("forgotPassword", "Username", nullptr));
        label_2->setText(QApplication::translate("forgotPassword", "Email", nullptr));
        label_3->setText(QApplication::translate("forgotPassword", "New-Password", nullptr));
        label_4->setText(QApplication::translate("forgotPassword", "Confirm Password", nullptr));
        pushButton_change->setText(QApplication::translate("forgotPassword", "Change", nullptr));
        pushButtonBack->setText(QApplication::translate("forgotPassword", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgotPassword: public Ui_forgotPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H
