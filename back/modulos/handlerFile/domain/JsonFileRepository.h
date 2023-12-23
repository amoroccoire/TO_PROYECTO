#ifndef JSONFILEREPOSITORY_H
#define JSONFILEREPOSITORY_H

// json_file_repository.h
#pragma once
#include "FileRepository.h"

class JsonFileRepository : public FileRepository {
private:
    QString ruta;
    QString file;

public:
    JsonFileRepository(std::string file = "");
    QJsonObject leerDatos() override;
    void escribirDatos(const QJsonObject& data) override;
};

#endif // JSONFILEREPOSITORY_H
