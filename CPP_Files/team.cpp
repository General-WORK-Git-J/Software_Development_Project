/* Implementation: Team
   Implements constructors and behaviors for `Team`, including adding heroes,
   displaying information and persisting teams to/from streams. The format used
   by `save`/`load` is a human-readable, line-oriented text format.
*/

#include "../Header_Files/team.h"
#include "../Header_Files/hero.h"
#include "../Header_Files/captain.h"

#include <algorithm>

using std::string;
using std::cout;
using std::endl;

// Constructors
Team::Team(string tn)
{
    teamName = tn;
    heroCount = 0;
}

// Default constructor
Team::Team()
{
    teamName = "";
    heroCount = 0;
}

// Parameterized constructor
Team::Team(string tn, Hero *h, int cnt)

{
    teamName = tn;
    heroCount = cnt;
    setHeroes(h);
};

void Team::setHeroes(Hero *h) {
    teamHeroes.clear();

    if (h == nullptr || heroCount <= 0) {
        heroCount = 0;
        return;
    }

    const int copyCount = heroCount > MAX_HEROES ? MAX_HEROES : heroCount;
    teamHeroes.assign(h, h + copyCount);
    syncHeroCount();
}

// Add a hero to the team
void Team::addHero(Hero h) {
    if (heroCount < MAX_HEROES) {
        teamHeroes.push_back(h);
        syncHeroCount();
    } else {
        cout << "Cannot add more heroes to the team. Maximum limit reached." << endl;
    }
};

// Display team information
void Team::displayTeamInfo() {
    cout << "Team Name: " << teamName << endl;
    cout << "Number of Heroes: " << heroCount << endl;
    cout << "Heroes in the Team:" << endl;
    for (const Hero &hero : teamHeroes) {
        cout << "- " << hero.getHeroName() << endl;
    }
};

// Display captain information
void Team::displayCaptainInfo() {
    cout << "Captain of the Team: " << endl;
    const Hero *captain = findCaptain();
    if (captain != nullptr) {
        cout << "- " << captain->getHeroName() << endl;
        return;
    }
    cout << "No captain assigned to this team." << endl;
};

Hero* Team::findHero(const string &heroName) {
    auto it = std::find_if(teamHeroes.begin(), teamHeroes.end(),
        [&heroName](const Hero &hero) {
            return hero.getHeroName() == heroName;
        });

    if (it == teamHeroes.end()) {
        return nullptr;
    }

    return &(*it);
}

const Hero* Team::findHero(const string &heroName) const {
    auto it = std::find_if(teamHeroes.begin(), teamHeroes.end(),
        [&heroName](const Hero &hero) {
            return hero.getHeroName() == heroName;
        });

    if (it == teamHeroes.end()) {
        return nullptr;
    }

    return &(*it);
}

Hero* Team::findCaptain() {
    auto it = std::find_if(teamHeroes.begin(), teamHeroes.end(),
        [](const Hero &hero) {
            return hero.getCaptainStatus();
        });

    if (it == teamHeroes.end()) {
        return nullptr;
    }

    return &(*it);
}

const Hero* Team::findCaptain() const {
    auto it = std::find_if(teamHeroes.begin(), teamHeroes.end(),
        [](const Hero &hero) {
            return hero.getCaptainStatus();
        });

    if (it == teamHeroes.end()) {
        return nullptr;
    }

    return &(*it);
}

// Save team information to a stream
void Team::save(std::ostream &os) const {
    os << teamName << std::endl;
    os << teamHeroes.size() << std::endl;
    for (const Hero &h : teamHeroes) {
        // name|health|attack|weakness|captainStatus|isAlive
        os << h.getHeroName() << "|" << h.getHealth() << "|" << h.getAttack() << "|" << h.getWeakness() << "|" << (h.getCaptainStatus() ? 1 : 0) << "|" << (h.getAlive() ? 1 : 0) << std::endl;
    }
    os << "----" << std::endl;
}

// Load team information from a stream
bool Team::load(std::istream &is) {
    teamHeroes.clear();
    heroCount = 0;

    if (!std::getline(is, teamName)) return false;
    std::string line;
    if (!std::getline(is, line)) return false;
    int declaredHeroCount = 0;
    try {
        declaredHeroCount = std::stoi(line);
    } catch (...) {
        heroCount = 0;
        return false;
    }

    for (int i = 0; i < declaredHeroCount; ++i) {
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
        if (static_cast<int>(teamHeroes.size()) < MAX_HEROES) {
            teamHeroes.push_back(h);
        }
    }
    syncHeroCount();
    
    // read separator
    std::string sep;
    if (!std::getline(is, sep)) return false;
    return sep == "----";
}