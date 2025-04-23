#include "sqllite.h"
#include "ui_sqllite.h"

SQLlite::SQLlite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SQLlite)
{
    ui->setupUi(this);
}

SQLlite::~SQLlite()
{
    delete ui;
}
