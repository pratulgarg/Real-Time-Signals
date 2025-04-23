#include "forgotpassword.h"
#include "ui_forgotpassword.h"
#include <QSqlDatabase>
#include <QFile>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QSqlError>
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QTextStream>
#include <QMessageBox>



forgotPassword::forgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotPassword)
//   mainwindow(nullptr)
{
    ui->setupUi(this);


        ui ->lineEdit_fp1->  setPlaceholderText("Username");
        ui -> lineEdit_fp2-> setPlaceholderText("Email");
        ui ->lineEdit_fp3->  setPlaceholderText("*******");
        ui ->lineEdit_fp4->  setPlaceholderText("*******");

        ui -> lineEdit_fp1->setClearButtonEnabled(true);
        ui -> lineEdit_fp3->setClearButtonEnabled(true);
        ui -> lineEdit_fp4->setClearButtonEnabled(true);

        ui ->lineEdit_fp3-> setEchoMode(QLineEdit::PasswordEchoOnEdit);
        ui ->lineEdit_fp4-> setEchoMode(QLineEdit::PasswordEchoOnEdit);

        QRegularExpression emailRegex("^[\\w.-]+@[\\w-]+\\.[a-zA-Z]{2,}$");
          QRegularExpressionValidator *validator = new QRegularExpressionValidator(emailRegex, this);
          ui->lineEdit_fp2->setValidator(validator);

          initializeDatabase();

      }
void forgotPassword::initializeDatabase() {



db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("info.db");

if (!db.open()) {
    QMessageBox::critical(nullptr, "Database Error", "Failed to open the database: " + db.lastError().text());
} else {
        qDebug() << "Database connection successful!";
    }
}
forgotPassword::~forgotPassword()
{
    delete ui;
//    if (mainwindow) {
//            delete mainwindow;
//            mainwindow = nullptr;
//    }
}

void forgotPassword::on_pushButton_change_clicked()
{


    QString username = ui->lineEdit_fp1->text();
        QString email = ui->lineEdit_fp2->text();
        QString newPassword = ui->lineEdit_fp3->text();
        QString confirmPassword = ui->lineEdit_fp4->text();

        if (username.isEmpty() || email.isEmpty() || newPassword.isEmpty() || confirmPassword.isEmpty()) {
              QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
              return; }

        if (newPassword != confirmPassword) {
               QMessageBox::warning(this, "Password Mismatch", "The new password and confirmation do not match.");
               return;
           }

         QString hashedPassword = QString(QCryptographicHash::hash(newPassword.toUtf8(), QCryptographicHash::Sha256).toHex());

         QSqlQuery query;

         query.prepare("SELECT * FROM users WHERE username = :username AND email = :email");
           query.bindValue(":username", username);
           query.bindValue(":email", email);

         if (!query.exec()) {
                   QMessageBox::critical(this, "Database Error", query.lastError().text());
                   return;
               }
         if (!query.next()) {
                 QMessageBox::warning(this, "Invalid User", "No matching user found with the provided username and email.");
                 return;
             }


             query.prepare("UPDATE users SET password = :password WHERE username = :username AND email = :email");
             query.bindValue(":password", hashedPassword);
             query.bindValue(":username", username);
             query.bindValue(":email", email);


          if (!query.exec()) {
                     QMessageBox::critical(this, "Database Error", query.lastError().text());
                     return;
                 }

            QMessageBox::information(this, "success", "password updated");

            ui->lineEdit_fp1->clear();
               ui->lineEdit_fp2->clear();
               ui->lineEdit_fp3->clear();
               ui->lineEdit_fp4->clear();

//               close();



}


void forgotPassword::on_pushButtonBack_clicked()
{

        // Close the current forgotPassword dialog
        this->close();

        // Show the parent MainWindow if it exists
        if (QWidget *parent = parentWidget()) {
            parent->show();
        }
    }






