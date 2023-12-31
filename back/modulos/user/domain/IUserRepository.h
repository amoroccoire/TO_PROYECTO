#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "user.h"

class IUserRepository {
public:
    virtual User* createUser(User*) = 0;
    virtual User* verifyUser(User*) = 0;
    virtual bool containUser(User*) = 0;
    virtual ~IUserRepository() = default;
};

#endif // IUSERREPOSITORY_H
