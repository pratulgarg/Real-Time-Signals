/********************************************************************************
** Form generated from reading UI file 'registerit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERIT_H
#define UI_REGISTERIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registerit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_Reusername;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_Repassword;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_ReRepassword;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_ReRepassword_email;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QRadioButton *radiobutton_Male;
    QRadioButton *radioButton_Female;
    QPushButton *pushButton;
    QPushButton *pushButton_back;

    void setupUi(QDialog *registerit)
    {
        if (registerit->objectName().isEmpty())
            registerit->setObjectName(QString::fromUtf8("registerit"));
        registerit->resize(817, 470);
        verticalLayout = new QVBoxLayout(registerit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(registerit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_Reusername = new QLineEdit(registerit);
        lineEdit_Reusername->setObjectName(QString::fromUtf8("lineEdit_Reusername"));

        horizontalLayout_3->addWidget(lineEdit_Reusername);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(registerit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_Repassword = new QLineEdit(registerit);
        lineEdit_Repassword->setObjectName(QString::fromUtf8("lineEdit_Repassword"));

        horizontalLayout_5->addWidget(lineEdit_Repassword);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(registerit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_ReRepassword = new QLineEdit(registerit);
        lineEdit_ReRepassword->setObjectName(QString::fromUtf8("lineEdit_ReRepassword"));

        horizontalLayout_6->addWidget(lineEdit_ReRepassword);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(registerit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_ReRepassword_email = new QLineEdit(registerit);
        lineEdit_ReRepassword_email->setObjectName(QString::fromUtf8("lineEdit_ReRepassword_email"));

        horizontalLayout_4->addWidget(lineEdit_ReRepassword_email);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(registerit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        radiobutton_Male = new QRadioButton(registerit);
        radiobutton_Male->setObjectName(QString::fromUtf8("radiobutton_Male"));

        horizontalLayout->addWidget(radiobutton_Male);

        radioButton_Female = new QRadioButton(registerit);
        radioButton_Female->setObjectName(QString::fromUtf8("radioButton_Female"));

        horizontalLayout->addWidget(radioButton_Female);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(registerit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_back = new QPushButton(registerit);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(pushButton_back);


        retranslateUi(registerit);

        QMetaObject::connectSlotsByName(registerit);
    } // setupUi

    void retranslateUi(QDialog *registerit)
    {
        registerit->setWindowTitle(QApplication::translate("registerit", "Dialog", nullptr));
        label->setText(QApplication::translate("registerit", "username   ", nullptr));
        lineEdit_Reusername->setText(QString());
        label_3->setText(QApplication::translate("registerit", "password     ", nullptr));
        lineEdit_Repassword->setText(QString());
        label_5->setText(QApplication::translate("registerit", "re-password", nullptr));
        lineEdit_ReRepassword->setText(QString());
        label_2->setText(QApplication::translate("registerit", "  Email            ", nullptr));
        lineEdit_ReRepassword_email->setText(QString());
        label_4->setText(QApplication::translate("registerit", "gender", nullptr));
        radiobutton_Male->setText(QApplication::translate("registerit", "male", nullptr));
        radioButton_Female->setText(QApplication::translate("registerit", "female", nullptr));
        pushButton->setText(QApplication::translate("registerit", "Save", nullptr));
        pushButton_back->setText(QApplication::translate("registerit", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerit: public Ui_registerit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERIT_H
