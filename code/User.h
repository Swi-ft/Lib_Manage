#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string name;
    std::string password;

    User(std::string name, std::string password);
};

#endif // USER_H
