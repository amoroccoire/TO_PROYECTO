#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "../../back/modulos/handlerFile/domain/JsonFileRepository.h"
#include "../../back/modulos/user/infraestructure/userfilerepository.h"
#include "../../back/modulos/user/application/verifyuser.h"

namespace Ui {
class logIn;
}

class logIn : public QWidget
{
    Q_OBJECT

public:
    explicit logIn(QWidget *parent = nullptr);
    ~logIn();

private slots:
    void on_iniciarSesion_clicked();

private:
    Ui::logIn *ui;
    JsonFileRepository* jsonfileUser;
    UserFileRepository* userFileRepo;
    VerifyUser* verifyUser;

};

#endif // LOGIN_H
