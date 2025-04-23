#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class register_class: public QDialog{
    Q_OBJECT



public:
    explicit register_class(QWidget *parent = nullptr);
    ~register_class();

private:
    Ui::register_class *ui;
};
}
#endif // REGISTER_H
