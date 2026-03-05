#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;
using std::ios;
using std::cerr;
using std::cin;
using std::pair;
using std::map;


struct User {
    string username;
    string password;
    string role; // e.g., "admin", "user"
};

class UserSystem {

private:

    map<string, User> users;
    string currentUser;
    

public:
    UserSystem();
    void loadUsers();
    void saveUsers();

    bool registerUser(const string & username, const string password, const string role);
    
    bool loginUser(const string & username, const string & password);
    void logoutUser();
    bool isAdmin();


    string getCurrentUser() 
        { return currentUser; }

};

#endif
/*  Header file for the User System, which includes the Admin class that manages heroes, teams, and captains in the Hero-Agency-Management project. 
    The Admin class includes member variables for the admin's name and count, as well as member functions to create heroes, create teams, assign captains, and display team information.
*/

