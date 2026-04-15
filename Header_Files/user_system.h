#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "admin.h"

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

// User structure to hold user information
struct User {
    string username;
    string password;
    string role; // e.g., "admin", "user"
};

// UserSystem class to manage user registration, login, and role-based access
// Exposes `getCurrentUserRole()` for permission checks used by Admin methods.
class UserSystem : public Admin {

private:

// User management
    map<string, User> users;
    string currentUser;
    

public:

// Constructors
    UserSystem();
    void loadUsers();
    void saveUsers();

// General functions
    bool registerUser(const string & username, const string password, const string role);
    bool loginUser(const string & username, const string & password);
    void logoutUser();
    bool isAdmin();

// Getters
    string getCurrentUser() 
        { return currentUser; }
    string getCurrentUserRole();
};

#endif
/*  Header file for the User System, which includes the Admin class that manages heroes, teams, and captains in the Hero-Agency-Management project. 
    The Admin class includes member variables for the admin's name and count, as well as member functions to create heroes, create teams, assign captains, and display team information.
*/

