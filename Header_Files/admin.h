// Admin interface: manage creation of heroes and teams with permission checks.
// Methods accept an optional `UserSystem*` to validate caller permissions.
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

#include "../Header_Files/hero.h"
#include "../Header_Files/team.h"
#include "../Header_Files/captain.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ios;
using std::cerr;

// Forward declare UserSystem to avoid circular includes
class UserSystem;

class Admin {
    
private:

    string adminName;
    int adminCount = 0;

public:

//Getters
    string getAdminName() {return adminName;}
    int getAdminCount() {return adminCount;}

//Setters
    void setAdminName(string n) {adminName = n;}
    void setAdminCount(int count) {adminCount = count;}

//General
    void createHero(string name, int health, int attack, string weakness, UserSystem* userSys = nullptr);
    void createTeam(string teamName, UserSystem* userSys = nullptr);
    void assignCaptain(Hero hero, Team team);
    void displayTeamInfo(Team team);
};

#endif