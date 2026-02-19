#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <iostream>
#include <string>
#include "hero.h"

class Captain {
    
private:

string captainName;
Team* team;
int captainCount = 0;

public:

//Getters
string getCaptainName(){return captainName;}
Team* getTeam(){return team;}
int getCaptainCount() {return captainCount;}

//Setters
void setCaptainName(string n) {captainName = n;}
void setTeam(Team* t) {team = t;}
void setCaptainCount(int count) {captainCount = count;}

//General
bool isMultipleCaptains();
void displayCaptainInfo();

//Constructors
Captain();
Captain(string name);
Captain(string name, Team* t);
Captain::Captain(string name, Team* t, int captainCount);
};

Captain::Captain() {
    captainName = "Unknown";
    team = nullptr;
    captainCount++;
};

Captain::Captain(string name) {
    captainName = name;
    team = nullptr;
    captainCount++;
};

#endif