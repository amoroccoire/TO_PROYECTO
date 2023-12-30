#include "../domain/JsonFileRepository.h"
#include <QJsonParseError>
#include <QDebug>

JsonFileRepository::JsonFileRepository(std::string file) {
    ruta = "../../../BASE_DATOS/";
    this->file = QString::fromStdString(file);
}

QJsonObject JsonFileRepository::leerDatos() {
    try {
        QString path = ruta + file;
        QFile archivo(path);

        if (!archivo.open(QIODevice::ReadWrite | QIODevice::Text)) {
            throw std::runtime_error("Error al abrir el archivo JSON.");
        }

        QJsonParseError error;
        QJsonDocument documento = QJsonDocument::fromJson(archivo.readAll(), &error);

        archivo.close();

        if (error.error != QJsonParseError::NoError) {
            throw std::runtime_error("Error al parsear el JSON: " + error.errorString().toStdString());
        }

        return documento.object();
    } catch (const std::exception& e) {
        qDebug() << "Error al leer datos: " << e.what();
        return QJsonObject();
    }
}

void JsonFileRepository::escribirDatos(const QJsonObject& data) {
    try {
        QString path = ruta + file;
        QFile archivo(path);

        if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            throw std::runtime_error("Error al abrir el archivo JSON para escritura.");
        }

        archivo.write(QJsonDocument(data).toJson(QJsonDocument::Indented));
        archivo.close();

        qDebug() << "Datos escritos exitosamente";
    } catch (const std::exception& e) {
        qDebug() << "Error al escribir datos: " << e.what();
    }
}
