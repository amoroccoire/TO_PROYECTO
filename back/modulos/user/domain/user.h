#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User();
    User(int, std::string, std::string);

    void setId(int);
    int getId();

    void setPas(std::string);
    std::string getPas();

    void setEmail(std::string);
    std::string getEmail();

    std::string toString();

private:
    int id;
    std::string password;
    std::string email;
};

#endif // USER_H
