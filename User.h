#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    int userID;
    string username;
    string password;

public:
    User(int id, string name, string pass);

    bool login(string inputUsername, string inputPassword);

    int getUserId() const;
    string getUsername() const;
    string getPassword() const;
};

#endif
