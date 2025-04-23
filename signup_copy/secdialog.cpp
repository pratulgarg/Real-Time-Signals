#include "secdialog.h"
#include "ui_secdialog.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QtCore/QDebug>
#include <cstdint>
#include <form.h>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QProcess>
#include "real_time.h"

SecDialog::SecDialog(QWidget *parent, Form* form) :
     QWidget(parent),
    ui(new Ui::SecDialog),
    udpSocket(nullptr),formPage(form)
{
    ui->setupUi(this);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    QVBoxLayout *layout = new QVBoxLayout(this);

//        // Add the existing widgets into the layout
//        layout->addWidget(ui->messageInput); // Assuming it's a QLineEdit or QT extEdit
//        layout->addWidget(ui->lineEdit);     // Another widget
//        layout->addWidget(ui->lineEdit_2);   // Another widget
//        layout->addWidget(ui->sendButton);

    if (!initializeSocket()) {
          QMessageBox::critical(this, "Error", "Failed to initialize UDP socket.");
}
}

SecDialog::~SecDialog(){
if (udpSocket){
    udpSocket ->close();
    delete udpSocket;
}
    delete ui;
}

bool SecDialog::initializeSocket(){
    try {
            udpSocket = new QUdpSocket(this);
            if (!udpSocket->bind(QHostAddress::Any, 0,QAbstractSocket::DefaultForPlatform)) {
              throw std::runtime_error("failed bind scoket");
                }
            qDebug()<<"Sender Udp socekt to bound port:"<<udpSocket->localPort();
            return true;
                        }  catch (const std::exception &e) {
            qDebug()<<"Socket initialization error"<<e.what();
            return false;
            }

        }
void SecDialog::sendMessage(const QString &message, const QString &ip, quint16 port){

     try {
         if (!udpSocket || !udpSocket->isValid()) {
             throw std::runtime_error("Socket not initialized or invalid.");
         }

         qint64 bytesSent = udpSocket->writeDatagram(message.toUtf8(), QHostAddress(ip), port);
         if (bytesSent == -1) {
             throw std::runtime_error("Failed to send message.");
         }

         qDebug() << "Message sent:" << message << "to IP:" << ip << "Port:" << port;
     }
     catch (const std::exception &e) {
            qDebug() << "Exception occurred while sending message:" << e.what();
        }
    }

void SecDialog::on_sendButton_clicked() {
    QString message = ui->messageInput->text();
    QString ip = ui->lineEdit->text();
    quint16 port = ui->lineEdit_2->text().toUShort();


    if (message.isEmpty() || ip.isEmpty() || port == 0) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }


    if (initializeSocket()) {
        sendMessage(message, ip, port);
        ui->messageInput->clear();
    }
    // Here, pass the port to Form constructor
//       Form *formPage = new Form(this, port);  // Pass port from SecDialog
//       formPage->show();
}


    void SecDialog::on_pushButton_clicked()
    {
    //       QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    //           qApp->quit();
             emit switchToMainWindow();
//        this -> close();

//    real_time *Realtime = new real_time(this);

//    Realtime->show();


     }



