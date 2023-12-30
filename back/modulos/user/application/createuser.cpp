#include "createuser.h"

CreateUser::CreateUser(IUserRepository* userRepository) {
    this->userRepository = userRepository;
    this->containUser = new ContainUser(userRepository);
}

User* CreateUser::execute(User *user) {
    //hace algo
    if (!containUser->execute(user)) {
        User* u = userRepository->createUser(user);
        return u;
    }
    return nullptr;
}
