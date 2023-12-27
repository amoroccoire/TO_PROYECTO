// filehandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QStringList>

class FileHandler
{
public:
    FileHandler(const QString& filePath);
    bool userExists(const QString& username, const QString& password);
    void agregarNuevoUsuario(const QString& username, const QString& password);

private:
    QString filePath;
};

#endif // FILEHANDLER_H

