/*  Header file for the Team class, which represents a team of heroes in a Hero-Agency-Management project. 
    The Team class includes member variables for the team name,
    an array of Hero objects,
    and the count of heroes in the team. 
    It also includes member functions to set and get these variables,
    as well as functions to add a hero to the team
    display information about the team and its captain.
*/

#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include "admin.h"

class Team {

private:
string teamName;
Hero* heroes;
int heroCount;
const static int MAX_HEROES = 10;
int teamCount = 0;
Hero teamHeroes[MAX_HEROES];

public:
//Getters 
string getTeamName() {return teamName;}
Hero* getHeroes() {return heroes;} 
int getHeroCount() {return heroCount;} 

//Setters
void setTeamName(string tn) {teamName = tn;} 
void setHeroes(Hero* h) {heroes = h;} 
void setHeroCount(int cnt) {heroCount = cnt;}

//General
void addHero(Hero h); 
void displayTeamInfo(); 
void displayCaptainInfo(); 

// Constructors
Team();
Team(string tn);
Team(string tn, Hero* h, int cnt);
Team(string tn, const static int maxH, Hero* h, int cnt);

};

Team::Team(string tn,const static int maxH, Hero* h, int cnt) { 

    teamName = tn;  
    heroes = h;  
    heroCount = cnt;  

};

#endif


