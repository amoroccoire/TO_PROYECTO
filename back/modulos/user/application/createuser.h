#ifndef CREATEUSER_H
#define CREATEUSER_H

#include "../domain/IUserRepository.h"

class CreateUser {
public:
    CreateUser(IUserRepository*);
    User* execute(const User*);

private:
    IUserRepository* userRepository;
};

#endif // CREATEUSER_H
