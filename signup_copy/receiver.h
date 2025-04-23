#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>
#include <QUdpSocket>


namespace Ui {
class receiver;
}

class receiver : public QWidget
{
    Q_OBJECT

public:
    explicit receiver(QWidget *parent = nullptr);
    ~receiver();


private:
    Ui::receiver *ui;
    QUdpSocket * udpSocekt;

//private slots:
//    void on_readyRead();
//    bool initializeSocket();
};


#endif // RECEIVER_H
