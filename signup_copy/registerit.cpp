#include "registerit.h"
#include "ui_registerit.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QCryptographicHash>
#include "utilities.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>


registerit::registerit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerit)
{
    ui->setupUi(this);
    ui ->lineEdit_Reusername ->setPlaceholderText("username");
    ui ->lineEdit_Repassword->setPlaceholderText("*******");
      ui->lineEdit_ReRepassword->setPlaceholderText("Confirm Password");
       ui->lineEdit_ReRepassword_email->setPlaceholderText("Enter Your Email");
         ui ->lineEdit_Repassword-> setEchoMode(QLineEdit::Password);
          ui ->lineEdit_ReRepassword-> setEchoMode(QLineEdit::PasswordEchoOnEdit);

    ui -> lineEdit_ReRepassword->setClearButtonEnabled(true);
    ui -> lineEdit_Repassword->setClearButtonEnabled(true);
     ui -> lineEdit_Reusername->setClearButtonEnabled(true);

     QRegularExpression emailRegex("^[\\w.-]+@[\\w-]+\\.[a-zA-Z]{2,}$");
        QRegularExpressionValidator *validator = new QRegularExpressionValidator(emailRegex, this);
        ui->lineEdit_ReRepassword_email->setValidator(validator);


       initializeDatabase();
}

registerit::~registerit()
{
    delete ui;

}


void registerit::initializeDatabase() {

    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
           QMessageBox::critical(this, "Database Error", "SQLite driver is not available.");
           return;
       }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("info.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }


    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            gender TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL
        );
    )";

    if (!query.exec(createTableQuery)) {
        QMessageBox::critical(nullptr, "Database Error", "Failed to create table: " + query.lastError().text());
    } else {
        qDebug() << "Database initialized successfully.";
    }
}

QString hashPassword(const QString &password) {
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}


void registerit::on_pushButton_clicked()
{

QString username = ui->lineEdit_Reusername->text();
    QString password = ui->lineEdit_Repassword->text();
      QString confirmPassword = ui->lineEdit_ReRepassword->text();
      QString email = ui ->lineEdit_ReRepassword_email->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Registration Error", "Passwords do not match.");
        return;
    }

     QString hashedPassword = hashPassword(password);

//    QFile file("Information.txt");
//        if (file.open(QIODevice::Append | QIODevice::Text)) {
//            QTextStream out(&file);
//            QMessageBox ::information(this, "registered","successful");

//             out << username << " " << password << "\n";

//             file.close();

//     initializeDatabase(   db);

         if (!ui->lineEdit_ReRepassword_email->hasAcceptableInput()) {
             QMessageBox::warning(this, "Email Error", "Please enter a valid email address.");
             return;
         }

     QString gender;
        if (ui->radiobutton_Male->isChecked()) {
            gender = "Male";
        } else if (ui->radioButton_Female->isChecked()) {
            gender = "Female";
        } else {
            QMessageBox::warning(this, "Registration Error", "Please select a gender.");
            return;
        }

    QSqlQuery query(db);
       query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");


       if (!query.exec()) {
           QMessageBox::critical(this, "Database Error", "Failed to check existing users: " + query.lastError().text());
           return;
       }

       query.next();  // Move to the first result row
       if (query.value(0).toInt() > 0) {
           QMessageBox::warning(this, "Registration Error", "Username already exists. Please choose another.");
           return;
       }


       qDebug() << "Username: " << username;
         qDebug() << "Password: " << password;
         qDebug() << "Gender: " << gender;
         qDebug() << "Email: " << email;

       // Insert new user into database
       query.prepare("INSERT INTO users (username, password, gender, email) VALUES (:username, :password, :gender, :email)");
       query.bindValue(":username", username);
       query.bindValue(":password", hashedPassword);
       query.bindValue(":gender", gender);
       query.bindValue(":email", email);

       if (query.exec()) {
           QMessageBox::information(this, "Registration Successful", "User registered successfully!");
               } else {
                   QMessageBox::critical(this, "Error", "Failed to register user: " + query.lastError().text());
               }

             if (db.isOpen()) {
                 db.close();
             }
          close();
mainwindow = new MainWindow(this);
mainwindow->show();
}

void registerit::on_pushButton_back_clicked()
{
close();
//mainwindow->show();
mainwindow = new MainWindow(this);
mainwindow->show();
//exec();

}

