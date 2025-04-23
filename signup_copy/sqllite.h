#ifndef SQLLITE_H
#define SQLLITE_H

#include <QDialog>

namespace Ui {
class SQLlite;
}

class SQLlite : public QDialog
{
    Q_OBJECT

public:
    explicit SQLlite(QWidget *parent = nullptr);
    ~SQLlite();

private:
    Ui::SQLlite *ui;
};

#endif // SQLLITE_H
