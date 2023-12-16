#include "createuser.h"

CreateUser::CreateUser(IUserRepository* userRepository) {
    this->userRepository = userRepository;
}

User* CreateUser::execute(const User *user) {
    //hace algo
    User* u = userRepository->createUser(user);
    if (u)
        return u;
    return nullptr;
}
