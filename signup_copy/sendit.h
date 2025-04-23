#ifndef SENDIT_H
#define SENDIT_H

#include <QMainWindow>
#include <QObject>
#include <QThread>
#include <QTimer>

class sendit : public QThread
{
    Q_OBJECT

public:
    sendit();
     explicit sendit(QObject *parent = nullptr);

signals:
    void dataSent(const QString &message);

protected:
    void run()override;

};


#endif // SENDIT_H
