#include "form.h"
#include "ui_form.h"
#include "login.h"
#include <QFile>
#include <QTextStream>
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

    //Se verifica si el usuario ya existe
    if (usuarioExiste(nombre)) {
        ui->label4->setVisible(true);
        ui->label5->setVisible(false);
    } else {
        //Si el usuario no existe
        agregarNuevoUsuario(nombre, contrasena);
        ui->label4->setVisible(false);
        ui->label5->setVisible(true);

        //Temporizador para cerrar la ventana después de 2 segundos
        QTimer::singleShot(1000, this, &Form::cerrarVentana);
    }
}

bool Form::usuarioExiste(const QString& nombre){
    QFile file("register.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("No se pudo abrir el archivo.");   //PARA SABER EN MODO CONSOLA
        return false;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split(';');

        if (datos.size() == 2) {
            QString usuario = datos[0];

            if (usuario == nombre) {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

void Form::agregarNuevoUsuario(const QString& nombre, const QString& contrasena)
{
    QFile file("register.csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning("No se pudo abrir el archivo para agregar el nuevo usuario.");
        return;
    }

    QTextStream out(&file);
    out << nombre << ";" << contrasena << "\n";

    file.close();
}

void Form::cerrarVentana()
{
    //Cerrar la ventana
    close();

    //Se abre la ventana de login
    login* loginWindow = new login();
    loginWindow->show();
}
