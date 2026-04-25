/* Team class
   Represents a collection of `Hero` objects with simple persistence support.
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
//keeps herocount matched to the size of the vector since it may be modified by add/remove hero functions.
    void syncHeroCount() { heroCount = static_cast<int>(teamHeroes.size()); }

public:

    // Getters
    string getTeamName() const { return teamName; }
    Hero* getHeroes() { return teamHeroes.empty() ? nullptr : teamHeroes.data(); }
    //const so team data can be displayed
    const Hero* getHeroes() const { return teamHeroes.empty() ? nullptr : teamHeroes.data(); }
    int getHeroCount() const { return heroCount; }

    // Setters
    void setTeamName(string tn) { teamName = tn; }
    void setHeroes(Hero* h);
    void setHeroCount(int cnt) { heroCount = cnt; }

    // General
    void addHero(Hero h);

    //marked const so teams can be displayed through a const reference.
    void displayTeamInfo() const;
    void displayFullTeamInfo() const;
    

    // NEW CODE: marked const so teams can be displayed through a const reference.
    void displayCaptainInfo() const;
    Hero* findHero(const string &heroName);

    const Hero* findHero(const string &heroName) const;
    Hero* findCaptain();
    const Hero* findCaptain() const;

    //removes a hero from the team by name.
    bool removeHeroByName(const string &heroName);
    bool removeCaptainStatusFromHero(const string &heroName);
    void sortHeroesAlphabetically();
    bool operator<(const Team& other) const { return teamName < other.teamName; }

    // Persistence
    void save(std::ostream &os) const;
    bool load(std::istream &is);

    // Constructors
    Team();
    Team(string tn);
    Team(string tn, Hero* h, int cnt);
};

#endif