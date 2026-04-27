#include "User.h"

User::User(int id, string name, string pass)
{
    userID = id;
    username = name;
    password = pass;
}

bool User::login(string inputUsername, string inputPassword)
{
    return (username == inputUsername && password == inputPassword);
}

int User::getUserId() const { return userID; }
string User::getUsername() const { return username; }
string User::getPassword() const { return password; }