#include "user_system.h"
#include "admin.h"
#include "hero.h"
#include "team.h"
#include "captain.h"
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


UserSystem::UserSystem() {
    loadUsers();
}

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

bool UserSystem::registerUser(const string & username, const string password, const string role) {
    if (users.count(username)) {
        return false; // Username already exists
    }
    users[username] = {username, password, role};
    saveUsers(); // Save the updated user list
    return true;
}

bool UserSystem::loginUser(const string & username, const string & password) {
    if (users.count(username) && users[username].password == password) {
        currentUser = username;
        return true; // Login successful
    }
    return false; // Login failed
}

void UserSystem::logoutUser() {
    currentUser.clear();

}

bool UserSystem::isAdmin() {
    for (const auto& user : users) {
        if (user.first == currentUser && user.second.role == "admin") {
            return true;
        }
    }
    return false;
}
