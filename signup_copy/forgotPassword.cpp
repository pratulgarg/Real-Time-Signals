#include "forgotPassword.h"
#include "ui_forgotpassword.h"
#include "mainwindow.h"

forgotPassword::forgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotPassword)
{
    ui->setupUi(this);
}

forgotPassword::~forgotPassword()
{
    delete ui;
}

void forgotPassword::on_pushButton_clicked()
{

}

