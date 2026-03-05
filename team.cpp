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

Team::Team(string tn)
{
    teamName = tn;
    heroes = nullptr;
    heroCount = 0;
}

Team::Team()
{
    teamName = "";
    heroes = nullptr;
    heroCount = 0;
}

Team::Team(string tn, Hero *h, int cnt)

{

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

void Team::save(std::ostream &os) const {
    os << teamName << std::endl;
    os << heroCount << std::endl;
    for (int i = 0; i < heroCount; ++i) {
        const Hero &h = teamHeroes[i];
        // name|health|attack|weakness|captainStatus|isAlive
        os << h.getHeroName() << "|" << h.getHealth() << "|" << h.getAttack() << "|" << h.getWeakness() << "|" << (h.getCaptainStatus() ? 1 : 0) << "|" << (h.getAlive() ? 1 : 0) << std::endl;
    }
    os << "----" << std::endl;
}

bool Team::load(std::istream &is) {
    if (!std::getline(is, teamName)) return false;
    std::string line;
    if (!std::getline(is, line)) return false;
    try {
        heroCount = std::stoi(line);
    } catch (...) {
        heroCount = 0;
        return false;
    }
    for (int i = 0; i < heroCount && i < MAX_HEROES; ++i) {
        if (!std::getline(is, line)) return false;
        // parse fields
        size_t p = 0, q;
        q = line.find('|', p); if (q==std::string::npos) return false; std::string name = line.substr(p, q-p); p = q+1;
        q = line.find('|', p); if (q==std::string::npos) return false; int health = std::stoi(line.substr(p, q-p)); p = q+1;
        q = line.find('|', p); if (q==std::string::npos) return false; int attack = std::stoi(line.substr(p, q-p)); p = q+1;
        q = line.find('|', p); if (q==std::string::npos) return false; std::string weakness = line.substr(p, q-p); p = q+1;
        q = line.find('|', p); if (q==std::string::npos) return false; bool cap = (line.substr(p, q-p) != "0"); p = q+1;
        bool alive = (line.substr(p) != "0");
        Hero h(name, health, attack, weakness, cap, alive);
        teamHeroes[i] = h;
    }
    // read separator
    std::string sep;
    std::getline(is, sep);
    return true;
}
