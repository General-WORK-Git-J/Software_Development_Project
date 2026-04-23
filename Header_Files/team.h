/* Team class
   Represents a collection of `Hero` objects with simple persistence support.
   Teams can save/load themselves to a text stream using `save`/`load`.
*/

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>

#include "../Header_Files/hero.h"

using std::string;
using std::vector;

class Team {

private:

    string teamName;
    vector<Hero> teamHeroes;
    int heroCount = 0;
    const static int MAX_HEROES = 10;
    int teamCount = 0;

    void syncHeroCount() { heroCount = static_cast<int>(teamHeroes.size()); }

public:

//Getters 
    string getTeamName() const {return teamName;}
    Hero* getHeroes() {return teamHeroes.empty() ? nullptr : teamHeroes.data();}
    const Hero* getHeroes() const {return teamHeroes.empty() ? nullptr : teamHeroes.data();}
    int getHeroCount() const {return heroCount;} 

//Setters
    void setTeamName(string tn) {teamName = tn;} 
    void setHeroes(Hero* h);
    void setHeroCount(int cnt) {heroCount = cnt;}

//General
    void addHero(Hero h); 
    void displayTeamInfo(); 
    void displayCaptainInfo(); 
    Hero* findHero(const string &heroName);
    const Hero* findHero(const string &heroName) const;
    Hero* findCaptain();
    const Hero* findCaptain() const;
    
// Persistence
    void save(std::ostream &os) const;
    bool load(std::istream &is);

// Constructors
    Team();
    Team(string tn);
    Team(string tn, Hero* h, int cnt);

};

#endif


