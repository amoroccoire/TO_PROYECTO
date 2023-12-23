#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#pragma once
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class FileRepository {
public:
    virtual ~FileRepository() = default;
    virtual QJsonObject leerDatos() = 0;
    virtual void escribirDatos(const QJsonObject& data) = 0;
};

#endif // FILEREPOSITORY_H
