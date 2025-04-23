#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

#include <QSqlDatabase>
#include <QDialog>
#include<QMacNativeWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QMainWindow>

namespace Ui {
class forgotPassword;
}

class forgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit forgotPassword(QWidget *parent = nullptr);
    ~forgotPassword();

private slots:
    void on_pushButton_change_clicked();


    void on_pushButtonBack_clicked();

private:
    Ui::forgotPassword *ui;

    QSqlDatabase db;
        void initializeDatabase();
        QMainWindow *mainwindow;
};

#endif // FORGOTPASSWORD_H
