#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <iostream>
#include <string>
#include "hero.h"
#include "team.h"

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
Captain::Captain();
Captain::Captain(string name, int count);
Captain::Captain(string name, Team* t, int count);
Captain::Captain(string name, Team* t, int captainCount);
};

#endif