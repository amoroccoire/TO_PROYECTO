#include "login.h"
#include "ui_login.h"
#include <QDebug>

logIn::logIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);
    jsonfileUser = new JsonFileRepository("user.json");
    userFileRepo = new UserFileRepository(jsonfileUser);
    verifyUser = new VerifyUser(userFileRepo);
    qDebug() << "constructor";
}

logIn::~logIn()
{
    delete ui;
}


void logIn::on_iniciarSesion_clicked()
{
    QString mail = ui->email->toPlainText();
    QString pass = ui->password->toPlainText();
    qDebug() << mail << " - " << pass;
    if (mail != "" && pass != "") {
        qDebug() << mail << " - " << pass;
    }
}

