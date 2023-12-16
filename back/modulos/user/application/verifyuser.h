#ifndef VERIFYUSER_H
#define VERIFYUSER_H

#include "../domain/IUserRepository.h"

class VerifyUser {
public:
    VerifyUser(IUserRepository*);

    User* execute(const User*);

private:
    IUserRepository* userRepository;
};

#endif // VERIFYUSER_H
