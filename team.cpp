/* 
    Implementation file for the Team class, including constructors and member functions,
    which defines the properties of teams in our Hero-Agency-Management project.
*/

#include "team.h"
#include "hero.h"
#include "captain.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;

Team::Team(string tn,const static int maxH, Hero* h, int cnt) { 

    teamName = tn;  
    heroes = h;  
    heroCount = cnt;  

};

void Team::addHero(Hero h) {
    if (heroCount < MAX_HEROES) {
        teamHeroes[heroCount] = h; // Add hero to the team array
        heroCount++; // Increment hero count
    } else {
        cout << "Cannot add more heroes to the team. Maximum limit reached." << endl;
    }
};

void Team::displayTeamInfo() {
    cout << "Team Name: " << teamName << endl;
    cout << "Number of Heroes: " << heroCount << endl;
    cout << "Heroes in the Team:" << endl;
    for (int i = 0; i < heroCount; i++) {
        cout << "- " << teamHeroes[i].getHeroName() << endl; // Display hero names
    }
};

void Team::displayCaptainInfo() {
    cout << "Captain of the Team: " << endl;
    for (int i = 0; i < heroCount; i++) {
        if (teamHeroes[i].getCaptainStatus()) { // Check if the hero is the captain
            cout << "- " << teamHeroes[i].getHeroName() << endl; // Display captain's name
            return; // Exit after finding the captain
        }
    }
    cout << "No captain assigned to this team." << endl; // If no captain is found
};
