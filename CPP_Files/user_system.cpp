#include "../Header_Files/user_system.h"
#include "../Header_Files/admin.h"
#include "../Header_Files/hero.h"
#include "../Header_Files/team.h"
#include "../Header_Files/captain.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using std::count;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

// UserSystem implementation
UserSystem::UserSystem() {
    loadUsers();
}

// Load users from a file
void UserSystem::loadUsers() {
    ifstream file("users.txt");
    if (!file.is_open()) {
        cerr << "Error opening users file." << endl;
        return;
    }

    users.clear();
    while (file) {
        User u;
        if (!(file >> u.username >> u.password >> u.role)) break;
        if (!u.username.empty())
            users[u.username] = u;
    }
    file.close();
    // Load users from a file
}

// Save users to a file
void UserSystem::saveUsers() {
    ofstream file("users.txt");
    for (auto & pair : users){
        file << pair.second.username << " " 
        << pair.second.password << " " 
        << pair.second.role << endl;
    }
    file.close();
    // Save users to a file (not implemented here)
}

// Register a new user
bool UserSystem::registerUser(const string & username, const string password, const string role) {
    if (users.count(username)) {
        return false; // Username already exists
    }
    users[username] = {username, password, role};
    saveUsers(); // Save the updated user list
    return true;
}

// Login a user
bool UserSystem::loginUser(const string & username, const string & password) {
    if (users.count(username) && users[username].password == password) {
        currentUser = username;
        return true; // Login successful
    }
    return false; // Login failed
}

// Logout the current user
void UserSystem::logoutUser() {
    currentUser.clear();
}

// Check if the current user is an admin
bool UserSystem::isAdmin() {
    for (const auto& user : users) {
        if (user.first == currentUser && user.second.role == "admin") {
            return true;
        }
    }
    return false;
}

// Return the role string for the current user (empty if none)
string UserSystem::getCurrentUserRole() {
    if (currentUser.empty()) return string();
    if (users.count(currentUser)) return users[currentUser].role;
    return string();
}