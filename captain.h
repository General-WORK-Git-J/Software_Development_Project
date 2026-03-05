#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <iostream>
#include <string>

class Team;
class Hero;

class Captain {
private:
    std::string captainName;
    Team* team;
    int captainCount = 0;

public:
    Captain();
    Captain(const std::string &name, Team* t, int count = 1);

    std::string getCaptainName() const { return captainName; }
    Team* getTeam() const { return team; }
    int getCaptainCount() const { return captainCount; }

    void setCaptainName(const std::string &n) { captainName = n; }
    void setTeam(Team* t) { team = t; }
    void setCaptainCount(int count) { captainCount = count; }

    bool isMultipleCaptains();
    void displayCaptainInfo();
    void assignCaptain(Hero hero, Team* team);
};

#endif