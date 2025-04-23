#include "receiverth.h"
#include <QDebug>
#include<QHostAddress>

receiverth::receiverth(QObject *parent) : QThread(parent), udpSocket(nullptr)
{
    udpSocket = new QUdpSocket(this);

    if(!udpSocket -> bind(QHostAddress::Any,12345))  {
        qDebug()<<"Failed to bind port";
    }
    connect(udpSocket,&QUdpSocket::readyRead, this,[this](){
        while (udpSocket->hasPendingDatagrams()){
            QByteArray datagram;
            datagram.resize(udpSocket->pendingDatagramSize());
            udpSocket-> readDatagram(datagram.data(), datagram.size());

            QString message = QString::fromUtf8(datagram);
            emit dataReceived(message);
        }

    });
}


receiverth::~receiverth()
{
if (udpSocket) {
udpSocket->close();
delete udpSocket;
}
}

void receiverth::run()
{
exec();  // Starts the event loop for the receiver thread
}

