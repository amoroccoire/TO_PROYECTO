#include "user.h"

User::User(){

}

User::User(int id, std::string password, std::string email) {
    this->id = id;
    this->password = password;
    this->email = email;
}

void User::setId(int id) {
    this->id = id;
}

int User::getId(){
    return this->id;
}

void User::setPas(std::string pass) {
    password = pass;
}

std::string User::getPas(){
    return this->password;
}

void User::setEmail(std::string email) {
    this->email = email;
}

std::string User::getEmail(){
    return this->email;
}

std::string User::toString(){
    return "{id: " + std::to_string(this->id) + ", email: " + this->email + ", password: " + this->password + "}";
}

