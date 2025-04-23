#ifndef FORM_H
#define FORM_H


//#include <QWidget>
#include <QDialog>
#include <QUdpSocket>
#include <QFileDialog>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

     void updateTextEdit(const QString &message);




private:
    Ui::Form *ui;
    QUdpSocket *udpSocket;
//    quint16 port;


private slots:
    void on_readyRead();
    void initializeSocket();

};





#endif // FORM_H
