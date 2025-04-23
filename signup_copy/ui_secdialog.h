/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *messageInput;
    QLabel *label_4;
    QPushButton *sendButton;

    void setupUi(QWidget *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->setProperty("modal", QVariant(false));
        SecDialog->setWindowModality(Qt::NonModal);
        SecDialog->setEnabled(true);
        SecDialog->resize(657, 470);
        SecDialog->setMaximumSize(QSize(1043, 16777215));
        SecDialog->setMouseTracking(false);
        SecDialog->setFocusPolicy(Qt::StrongFocus);
        SecDialog->setAcceptDrops(true);
        SecDialog->setLayoutDirection(Qt::LeftToRight);
        SecDialog->setProperty("sizeGripEnabled", QVariant(true));
        gridLayout = new QGridLayout(SecDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(SecDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMouseTracking(true);
        frame->setFocusPolicy(Qt::TabFocus);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"URW Gothic\";\n"
""));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"font: 75 10pt \"Vemana2000\";\n"
"\n"
"    border: none; /* Removes the border */\n"
"    background-color: transparent; /* Transparent background */\n"
"    color: black; /* Default text color */\n"
"\n"
"\n"
"hover {\n"
"    background-color: white; /* Changes background color on hover */\n"
"    color: black; /* Keeps the text color black on hover */\n"
"}"));
        pushButton->setAutoRepeat(true);

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setDragEnabled(false);
        lineEdit_2->setClearButtonEnabled(false);

        gridLayout_2->addWidget(lineEdit_2, 4, 0, 1, 1);

        messageInput = new QLineEdit(frame);
        messageInput->setObjectName(QString::fromUtf8("messageInput"));
        sizePolicy.setHeightForWidth(messageInput->sizePolicy().hasHeightForWidth());
        messageInput->setSizePolicy(sizePolicy);
        messageInput->setTabletTracking(true);
        messageInput->setDragEnabled(true);
        messageInput->setReadOnly(false);

        gridLayout_2->addWidget(messageInput, 7, 0, 1, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        sendButton = new QPushButton(frame);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(sendButton, 8, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, messageInput);
        QWidget::setTabOrder(messageInput, pushButton);
        QWidget::setTabOrder(pushButton, frame);

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QWidget *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Widget", nullptr));
        label_2->setText(QApplication::translate("SecDialog", "ip", nullptr));
        label_3->setText(QApplication::translate("SecDialog", "port", nullptr));
        label->setText(QApplication::translate("SecDialog", "Sender application", nullptr));
        pushButton->setText(QApplication::translate("SecDialog", "close", nullptr));
        label_4->setText(QApplication::translate("SecDialog", "send message", nullptr));
        sendButton->setText(QApplication::translate("SecDialog", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
