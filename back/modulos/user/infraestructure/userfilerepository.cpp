#include "userfilerepository.h"
//FROM QT
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>

UserFileRepository::UserFileRepository(FileRepository* fileRepository) {
    this->lista = new DoubleLinkedList<QString, User*>();
    this->fileRepository = fileRepository;
    toDoubleList();
}

void UserFileRepository::toDoubleList() {
    QJsonObject data = fileRepository->leerDatos();
    QJsonArray arrayUsuarios = data["user"].toArray();
    User* user;
    foreach (const QJsonValue &value, arrayUsuarios) {
        QJsonObject usuario = value.toObject();
        user = new User();
        user->setId(usuario["id"].toInt());
        user->setEmail(usuario["email"].toString().toStdString());
        user->setPas(usuario["password"].toString().toStdString());
        lista->insertLast(QString::fromStdString(user->getPas()), user);
    }
}

User* UserFileRepository::createUser(User *user) {

    try {
        QJsonObject data = fileRepository->leerDatos();

        QJsonObject newUser;

        newUser["id"] = user->getId();
        newUser["email"] = QString::fromStdString(user->getEmail());
        newUser["password"] = QString::fromStdString(user->getPas());

        data["user"].toArray().append(newUser);
        fileRepository->escribirDatos(data);

        qDebug() << "Usuario agregado exitosamente";
        return user;

    } catch(const std::exception& e) {
        qDebug() << "Error al crear usuario" << e.what();
    }
}

bool UserFileRepository::containUser(User *user) {
    User* rpta = lista->search(QString::fromStdString(user->getPas()))->getValue(QString::fromStdString(user->getPas()));

    if(rpta){
        return true;
    }
    return false;
}

User* UserFileRepository::verifyUser(User *user) {
    User* rpta = lista->search(QString::fromStdString(user->getPas()))->getValue(QString::fromStdString(user->getPas()));
    if(rpta)
        return rpta;
    return nullptr;
}

void UserFileRepository::setNameFile(const std::string file = "") {
    this->file = file;
}




