#include "form.h"
#include "ui_form.h"
#include "filehandler.h"
#include "login.h"
#include <QTimer>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->label4->setVisible(false);
    ui->label5->setVisible(false);
}

Form::~Form()
{
    delete ui;
}

void Form::on_btn1_clicked()
{
    QString nombre = ui->username->toPlainText();
    QString contrasena = ui->password->toPlainText();

    //Se crea instancia de fileHandler
    FileHandler fileHandler("register.csv");

    if (fileHandler.userExists(nombre, contrasena)) {
        ui->label4->setVisible(true);
        ui->label5->setVisible(false);
    } else {
        //En caso el usuario ya exista
        fileHandler.agregarNuevoUsuario(nombre, contrasena);
        ui->label4->setVisible(false);
        ui->label5->setVisible(true);

        //Temporizador
        QTimer::singleShot(2000, this, &Form::cerrarVentana);
    }
}

void Form::cerrarVentana()
{
    close();

    //Para abrir la ventana de login
    login* loginWindow = new login();
    loginWindow->show();
}