#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "registerit.h"
#include <QPixmap>
#include<QStringList>
#include <QTextStream>
#include "utilities.h"
#include <QCryptographicHash>
#include "form.h"
#include <QStackedWidget>
#include "secdialog.h"
#include "real_time.h"
//#include "forgotPassword.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)  


//    , stackedWidget(new QStackedWidget(this))
//    , formPage(new Form(this))
//        , secDialog(new QDialog(this))
{
    ui->setupUi(this);

//    setCentralWidget(stackedWidget);

//    stackedWidget->addWidget(formPage);
//    stackedWidget->addWidget(secDialog);

//    connect(formPage, &Form::switchtoSecDialog, this, &MainWindow::showSecDialogPage);
//       connect(secDialogPage, &SecDialog::switchToForm, this, &MainWindow::showFormPage);

//       // Show the initial page (Form)
//       stackedWidget->setCurrentWidget(formPage);

//    QPixmap pix("/home/pratul/Downloads/images.png");
//    int w  = ui->label_pic->width();
//    int h  = ui->label_pic->height();
//            ui->label_pic->setPixmap(pix.scaled(100,1000,Qt::KeepAspectRatio));

//    QFile File("Information");
//    if (File.open(QIODevice::Append | QIODevice:: ReadWrite) )
//    {
//        QTextStream stream(&File);
//        stream << "Information of user";
//    }
//            File.close();

  ui ->lineEdit_password->  setPlaceholderText("*******");
  ui -> lineEdit_username-> setPlaceholderText("Username");
  ui -> lineEdit_password->setClearButtonEnabled(true);
  ui -> lineEdit_username->setClearButtonEnabled(true);
  ui ->lineEdit_password -> setEchoMode(QLineEdit::Password);

//        ui->frame->setVisible(true);
}

MainWindow::~MainWindow()
{
    cleanupThreads();
    delete ui;
}

bool MainWindow::checkCredentials(const QString &username, const QString &password)
{

    QString hashedPassword =  Utilities::hashPassword(password);

    //    QSqlDatabase db = QSqlDatabase::database();


//    QFile file("Information.txt");
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        QTextStream in(&file);
//        QString line;
//        while (!in.atEnd()) {
//      //      line = in.readLine();
//              line = in.readLine().trimmed();
//            QStringList parts = line.split(" ");
//            if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
//                file.close();
//                return true;
//            }
//        }
//        file.close();
//    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("info.db");

        if (!db.open()) {
            QMessageBox::critical(this, "Database Error", "Failed to open database: " + db.lastError().text());
            return false;
        }

        // Prepare SQL query to check credentials
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", hashedPassword);


//        if (query.exec()) {
//            if (query.next()) {
//                // Valid credentials found
//                db.close();
//                return true;
//            } else {
//                // Invalid credentials
//                db.close();
//                return false;
//            }
        if (query.exec() && query.next()) {
               int count = query.value(0).toInt();
               db.close();
               return count > 0;

        } else {
            // Query execution failed
            QMessageBox::critical(this, "Query Error", "Query failed: " + query.lastError().text());
            db.close();

    return false;
        }
}


void MainWindow::showMainWindow()
{
    cleanupThreads();

  delete centralWidget();

//    setWindowFlags(Qt::Widget);
    real_time *Realtime = new real_time(this);

    Realtime->show();


  }


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(checkCredentials(username, password)) {
        QMessageBox ::information(this, "Login","Login successful");


//        ui->frame->setVisible(true);

        initializeThreads();


               formPage = new Form(this);
               secDialog = new SecDialog(this, formPage);

//               secDialog = new SecDialog(this);

                    connect(static_cast<SecDialog*>(secDialog), &SecDialog::switchToMainWindow, this, &MainWindow::showMainWindow);

               // Create a vertical layout
               QVBoxLayout* layout = new QVBoxLayout;

               // Add the widgets to the layout
               layout->addWidget(secDialog);
               layout->addWidget(formPage);



               // Create a container widget
               QWidget* stackedWidgetContainer = new QWidget(this);
               stackedWidgetContainer->setLayout(layout);

               // Show the container widget
                 setCentralWidget(stackedWidgetContainer);
               stackedWidgetContainer->show();

               // Resize the main window to fit the new layout




//        formPage = new Form(this);
//        formPage->show();


//        secDialog = new SecDialog(this);
//        secDialog ->show();

//        this->show();
        resize(900, 900);
        this->update(); // Make sure the layout is updated
          this->repaint(); // Ensure the window is repainted

}
    else{
        QMessageBox::warning(this,"Login","Invalid username and password");

    }
}

void MainWindow::initializeThreads()
{
    // Initialize and start receiver
    receiver = new receiverth(this);
    connect(receiver, &receiverth::dataReceived, this, &MainWindow::handleReceivedData);
    receiver->start();

    // Initialize and start sender
    sender = new sendit(this);
    connect(sender, &sendit::dataSent, receiver, &receiverth::dataReceived);
    sender->start();
}
void MainWindow::cleanupThreads()
{
    if (sender) {
        sender->quit();
        sender->wait();
        delete sender;
        sender = nullptr;
    }

    if (receiver) {
        receiver->quit();
        receiver->wait();
        delete receiver;
        receiver = nullptr;
    }
}

void MainWindow::handleReceivedData(const QString &message)
{
    qDebug() << "MainWindow received data: " << message;
//    QMessageBox::information(this, "Message Received", "Received: " + message);
    if (formPage) {
          formPage->updateTextEdit(message);
      }
}


void MainWindow::on_pushButton_register_clicked()
{
    this -> hide();

registerit *Registerit = new registerit(this);

Registerit->exec();



}




void MainWindow::on_pushButton_forgotPassword_clicked()
{
    this -> hide();

//forgotPassword ForgotPassword;
//ForgotPassword.setModal(true);
//ForgotPassword.exec();

    forgotPassword *forgotPasswordDialog = new forgotPassword(this);
    forgotPasswordDialog->exec();

}


void MainWindow::on_actioncopy_triggered()
{
real_time * realth = new real_time(this);
   realth->show();
}

