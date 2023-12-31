// filehandler.cpp
#include "filehandler.h"
#include <QFile>
#include <QTextStream>

FileHandler::FileHandler(const QString& filePath)
    : filePath(filePath)
{
}

bool FileHandler::userExists(const QString& username, const QString& password)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("No se pudo abrir el archivo.");
        return false;
    }

    QTextStream in(&file);
    bool userFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(';');

        if (data.size() == 2) {
            QString user = data[0];
            QString pass = data[1];

            if (user == username && pass == password) {
                userFound = true;
                break;
            }
        }
    }

    file.close();
    return userFound;
}

void FileHandler::agregarNuevoUsuario(const QString& username, const QString& password)
{
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning("No se pudo abrir el archivo para agregar el nuevo usuario.");
        return;
    }

    QTextStream out(&file);
    out << username << ";" << password << "\n";

    file.close();
}


