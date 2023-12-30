#include "containuser.h"

ContainUser::ContainUser(IUserRepository* userRepository) {
    this->userRepository = userRepository;
}

bool ContainUser::execute(User* user) {
    //hace algo
    return userRepository->containUser(user);
}
