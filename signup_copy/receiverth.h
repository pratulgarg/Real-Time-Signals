#ifndef RECEIVERTH_H
#define RECEIVERTH_H


#include <QObject>
#include <QThread>
#include <QUdpSocket>

class receiverth : public QThread
{   
    Q_OBJECT

public:
    explicit receiverth(QObject * parent = nullptr);
    ~receiverth();

signals:
    void dataReceived(const QString &message);

protected:
    void run() override;

private:
    QUdpSocket *udpSocket;
};

#endif // RECEIVERTH_H
