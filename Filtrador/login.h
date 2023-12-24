#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "form.h"


QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

private:
    Ui::login *ui;
};
#endif // LOGIN_H
