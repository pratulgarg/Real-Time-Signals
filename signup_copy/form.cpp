#include "form.h"
#include "ui_form.h"
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>
#include "form.h"
#include <QTextEdit>
#include <QNetworkInterface>
#include <QVBoxLayout>
#include "mainwindow.h"

Form::Form(QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::Form),
  udpSocket(nullptr)
{
    ui->setupUi(this);
setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    // Create a QVBoxLayout
   //        QVBoxLayout *layout = new QVBoxLayout(this);

//        // Add the existing widget (message update area) into the layout
//        layout->addWidget(ui->messageUpdate);
//        layout->addWidget(ui->label);

     initializeSocket();
}

Form::~Form()
{
    if (udpSocket) {
        udpSocket->close();
        delete udpSocket;
       }delete ui;
}

void Form::initializeSocket() {
//     quint16 port = ui->lineEdit_port->text().toUShort();
    try {
        udpSocket = new QUdpSocket(this);
        if (!udpSocket->bind(QHostAddress::Any, 9999)) {
            throw std::runtime_error("Failed to bind receiver socket.");
        }
        connect(udpSocket, &QUdpSocket::readyRead, this, &Form::on_readyRead);
        qDebug() << "Receiver UDP socket bound to port ."<< 9999;
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Socket initialization failed: %1").arg(e.what()));
        qDebug() << "Exception occurred while initializing receiver:" << e.what();
    }
}

void Form::on_readyRead() {
    QByteArray buffer;
    QHostAddress sender;
    quint16 senderPort;

    while (udpSocket->hasPendingDatagrams()) {
        buffer.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        QString receivedMessage = QString("Message from %1:%2 - %3")
                                  .arg(sender.toString()).arg(senderPort).arg(QString(buffer));
        ui->messageUpdate->append(receivedMessage);
        qDebug() << "Message Displayed  :: " << receivedMessage << "port" << senderPort;
    }
}

void Form::updateTextEdit(const QString &message)
{
    if (ui->messageUpdate) { // Assuming `messageUpdate` is the QTextEdit
        ui->messageUpdate->append(message);
    }
}

