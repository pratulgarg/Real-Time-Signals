#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "secdialog.h"
#include <QMainWindow>
#include <registerit.h>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "forgotpassword.h"
#include "form.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include "receiverth.h"
#include "sendit.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool checkCredentials(const QString &username, const QString &password);

private slots:
//    void on_login_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_forgotPassword_clicked();

    void handleReceivedData(const QString &message);

      void showMainWindow();

      void on_actioncopy_triggered();

private:
    Ui::MainWindow *ui;
   QWidget *secDialog;


         Form *formPage;

       forgotPassword *ForgotPassword;

           QSqlDatabase db;
//           QStackedWidget *stackedWidget;
           QVBoxLayout *stackedLayout; // To stack widgets vertically
           QWidget *containerWidget;   // To act as the container for layout

           receiverth *receiver;
           sendit *sender;

           void initializeThreads();
           void cleanupThreads();


            void initializeDatabase();

signals:
    void sendMessage(const QString &message);

};
#endif // MAINWINDOW_H
