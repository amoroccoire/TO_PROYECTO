#include "verifyuser.h"

VerifyUser::VerifyUser(IUserRepository* userRepository) {
    this->userRepository = userRepository;
}

User* VerifyUser::execute(User* user) {
    User* u = userRepository->verifyUser(user);
    if (u)
        return u;
    return nullptr;
}
