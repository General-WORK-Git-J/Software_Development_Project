#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "hero.h"
#include "team.h"
#include "captain.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ios;
using std::cerr;

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
    
    void createHero(string name, int health, int attack, string weakness);
    void createTeam(string teamName);
    void assignCaptain(Hero hero, Team team);
    void displayTeamInfo(Team team);

};

#endif