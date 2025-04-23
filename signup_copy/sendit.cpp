#include "sendit.h"

sendit::sendit(QObject* parent) :QThread(parent)
{

}

void sendit::run()
{
    QTimer timer;
    timer.moveToThread(this);

    connect(&timer, &QTimer::timeout, this, [this](){
         QString message = "Message from sender!";
        emit dataSent(message);
    });

    timer.start(3000);

   exec();

}
