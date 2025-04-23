
#ifndef REGISTERIT_H
#define REGISTERIT_H
#include "mainwindow.h"
#include <QDialog>
#include<QMacNativeWidget>
#include<QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class registerit;
}

class registerit : public QDialog
{
    Q_OBJECT

public:
    explicit registerit(QWidget *parent = nullptr);
    ~registerit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::registerit *ui;
  QMainWindow *mainwindow;
      QSqlDatabase db;

       void initializeDatabase();

};

#endif // REGISTERIT_H
