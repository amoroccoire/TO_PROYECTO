#include "login.h"
#include "./ui_login.h"
#include "filehandler.h"

login::login(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("Formulario");
    ui->label4->setVisible(false);
    ui->label5->setVisible(false);
}

login::~login()
{
    delete ui;
}

void login::on_btn1_clicked()
{
    QString nombre = ui->username->toPlainText();
    QString contrasena = ui->password->toPlainText();

    FileHandler fileHandler("register.csv");

    //Usando fileHanlder para verificar el ingreso
    if (fileHandler.userExists(nombre, contrasena)) {
        ui->label5->setVisible(true);
        ui->label4->setVisible(false);
    } else {
        ui->label5->setVisible(false);
        ui->label4->setVisible(true);
    }
}

void login::on_btn2_clicked()
{
    close();

    //Creando una instancia form
    Form *formWindow = new Form();
    formWindow->show();
}

