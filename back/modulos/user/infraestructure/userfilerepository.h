#ifndef USERFILEREPOSITORY_H
#define USERFILEREPOSITORY_H

#include "../domain/IUserRepository.h"

class UserFileRepository : public IUserRepository{
public:
    UserFileRepository();
    User* createUser(User *) override;
    bool containUser(User *) override;
    User* verifyUser(User *) override;
    void setNameFile(const std::string);

private:
    std::string file;
};

#endif // USERFILEREPOSITORY_H
