#include "windowupload.h"
#include "ui_windowupload.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QDebug>

WindowUpload::WindowUpload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowUpload)
{
    ui->setupUi(this);
}

WindowUpload::~WindowUpload()
{
    delete ui;
}

void WindowUpload::on_botonSubir_clicked() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Seleccionar archivo", QDir::homePath(), "Archivos (*.txt *.csv);;Todos los archivos (*.*)");
    if (!filePath.isEmpty()) {
        QString destino = QDir::currentPath() + "/../TO_PROYECTO/back/BASE_DATOS/" + QFileInfo(filePath).fileName();
        if (QFile::copy(filePath, destino)){
            qDebug() << "Archivo copiado con éxito a:" << destino;
            emit onSuccessUploadFile();
        }
        else
            qDebug() << "Error al copiar el archivo.";
    }
    else
        qDebug() << "Ningun archivo seleccionado";
}

