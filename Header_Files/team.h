/* Team class
   Represents a collection of `Hero` objects with simple persistence support.
   Teams can save/load themselves to a text stream using `save`/`load`.
*/

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>

#include "../Header_Files/hero.h"

class Team {

private:

    string teamName;
    Hero* heroes = nullptr;
    int heroCount = 0;
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
    
// Persistence
    void save(std::ostream &os) const;
    bool load(std::istream &is);

// Constructors
    Team();
    Team(string tn);
    Team(string tn, Hero* h, int cnt);

};

#endif


