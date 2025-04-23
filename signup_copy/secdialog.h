#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QFileDialog>
#include <QDialog>
#include <QUdpSocket>
#include <mainwindow.h>
#include<QMainWindow>
#include "form.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QWidget
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr, Form* form = nullptr);
    ~SecDialog();

private slots:
     void on_sendButton_clicked();

     void on_pushButton_clicked();

signals:
    void switchToMainWindow();


private:
    Ui::SecDialog *ui;
    QUdpSocket *udpSocket;
        bool initializeSocket();
        void sendMessage(const QString &message, const QString &ip, quint16 port);

        QMainWindow *window;
        Form * formPage;

};

#endif // SECDIALOG_H
