// Captain: lightweight wrapper representing a team's captain and helpers
#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// Forward declarations to avoid circular dependencies
class Team;
class Hero;

class Captain {

private:

    std::string captainName;
    Team* team;
    int captainCount = 0;

public:
// Constructors
    Captain();
    Captain(const string &name, Team* t, int count = 1);

// Getters
    string getCaptainName() const { return captainName; }
    Team* getTeam() const { return team; }
    int getCaptainCount() const { return captainCount; }

// Setters
    void setCaptainName(const string &n) { captainName = n; }
    void setTeam(Team* t) { team = t; }
    void setCaptainCount(int count) { captainCount = count; }

// General functions    
    bool isMultipleCaptains();
    void displayCaptainInfo();
    void assignCaptain(Hero hero, Team* team);
};

#endif