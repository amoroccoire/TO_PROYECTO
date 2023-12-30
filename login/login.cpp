#include "login.h"
#include "./ui_login.h"
#include "filehandler.h"
#include "./front/search/windowsearch.h"
#include <QTimer>

login::login(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("Formulario");
    ui->label4->setVisible(false);
    ui->label5->setVisible(false);

    //Para ocultar el texto de la contraseña
    ui->password->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_btn1_clicked()
{
    QString nombre = ui->username->text();
    QString contrasena = ui->password->text();

    FileHandler fileHandler("register.csv");

    //Usando fileHanlder para verificar el ingreso
    if (fileHandler.userExists(nombre, contrasena)) {
        qDebug() << "Usuario válido. Abriendo ventana windowSearch...";
        ui->label5->setVisible(true);
        ui->label4->setVisible(false);

        QTimer::singleShot(2000, this, &login::cerrarVentana);

    } else {
        qDebug() << "Usuario no válido";
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

void login::cerrarVentana()
{
    close();

    //Para abrir la ventana del programa principal
    windowSearch *searchWindow = new windowSearch();
    searchWindow->show();
}

