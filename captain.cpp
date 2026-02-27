#include "captain.h"
#include "team.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;


Captain::Captain() {
    captainName = "Unknown";
//    team = nullptr;
    captainCount++;
};

Captain::Captain(string name, int count) {
    captainName = name;
    team = nullptr;
   captainCount = count;
};

Captain::Captain(string name, Team* t, int count) {
    captainName = name;
    team = t;
    captainCount = count;
};

bool Captain::isMultipleCaptains() {
    if (captainCount > 1) {
        cout << "Warning: More than one captain created. Captain count: " << captainCount << endl;
        return true;
    }
    return false;
};

void Captain::displayCaptainInfo() {
    cout << "Captain Name: " << captainName << endl;
    cout << "Team Name: " << team->getTeamName() << endl;
    cout << "Heroes in the Team: " << team->getHeroCount() << endl;
    cout << "Captain's Hero Status: " << (team->getHeroes()[0].getCaptainStatus() ? "Yes" : "No") << endl; // Assuming the captain is the first hero in the team array
};

