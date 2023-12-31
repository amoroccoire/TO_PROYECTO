#ifndef USERFILEREPOSITORY_H
#define USERFILEREPOSITORY_H

#include "../domain/IUserRepository.h"
#include "../../handlerFile/domain/FileRepository.h"
#pragma once
#include "../../../../shared/DoubleLinkedList/doublelinkedlist.cpp"

class UserFileRepository : public IUserRepository{
public:
    UserFileRepository(FileRepository*);
    User* createUser(User *) override;
    bool containUser(User *) override;
    User* verifyUser(User *) override;
    void setNameFile(const std::string);

private:
    std::string file;
    std::string rutaBD;
    FileRepository* fileRepository;
    DoubleLinkedList<QString, User*>* lista;

    void toDoubleList();
};

#endif // USERFILEREPOSITORY_H
