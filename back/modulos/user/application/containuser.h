#ifndef CONTAINUSER_H
#define CONTAINUSER_H

#include "../domain/IUserRepository.h"

class ContainUser {
public:
    ContainUser(IUserRepository*);
    bool execute(const User*);

private:
    IUserRepository* userRepository;
};

#endif // CONTAINUSER_H
