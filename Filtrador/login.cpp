#include "login.h"
#include "./ui_login.h"
#include <QFile>
#include <QTextStream>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
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

    //Buscando el archivo csv (registrado previamente en CMakeList
    QFile file("register.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning("No se pudo abrir el archivo.");
        return;
    }

    QTextStream in(&file);
    bool usuarioEncontrado = false;

    //Diviendo los usuario y contraseñas por filas
    while (!in.atEnd()){
        QString linea = in.readLine();
        QStringList datos = linea.split(';');

        if (datos.size() == 2){
            QString usuario = datos[0];
            QString clave = datos[1];

            //Evaluando si el usuario y contraseña ingresados coinciden con el registro
            if (usuario == nombre && clave == contrasena){
                usuarioEncontrado = true;
                break;
            }
        }
    }

    file.close();

    if (usuarioEncontrado){
        ui->label5->setVisible(true);
        ui->label4->setVisible(false);
    } else {
        ui->label5->setVisible(false);
        ui->label4->setVisible(true);
    }
}


void login::on_btn2_clicked()
{
    //Para cerrar la ventana actual
    close();

    Form *formWindow = new Form();
    formWindow->show();
}

