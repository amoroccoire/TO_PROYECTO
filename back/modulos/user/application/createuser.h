#ifndef CREATEUSER_H
#define CREATEUSER_H

#include "../domain/IUserRepository.h"
#include "containuser.h"

class CreateUser {
public:
    CreateUser(IUserRepository*);
    User* execute(User*);

private:
    IUserRepository* userRepository;
    ContainUser* containUser;
};

#endif // CREATEUSER_H
