/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receiver
{
public:

    void setupUi(QWidget *receiver)
    {
        if (receiver->objectName().isEmpty())
            receiver->setObjectName(QString::fromUtf8("receiver"));
        receiver->resize(400, 300);

        retranslateUi(receiver);

        QMetaObject::connectSlotsByName(receiver);
    } // setupUi

    void retranslateUi(QWidget *receiver)
    {
        receiver->setWindowTitle(QApplication::translate("receiver", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receiver: public Ui_receiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
