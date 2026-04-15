#include "../Header_Files/captain.h"
#include <iostream>
#include "../Header_Files/team.h"

// Default constructor
Captain::Captain() {
    captainName = "Unknown";
    team = nullptr;
    captainCount = 0;
}

// Parameterized constructor
Captain::Captain(const std::string &name, Team* t, int count) {
    captainName = name;
    team = t;
    captainCount = count;
}

// General functions
bool Captain::isMultipleCaptains() {
    if (captainCount > 1) {
        std::cout << "Warning: More than one captain created. Captain count: " << captainCount << std::endl;
        return true;
    }
    return false;
}

// Assign a hero as the captain of a team
void Captain::displayCaptainInfo() {
    if (!team) {
        std::cout << "No team assigned to this captain." << std::endl;
        return;
    }
    std::cout << "Captain Name: " << captainName << std::endl;
    std::cout << "Team Name: " << team->getTeamName() << std::endl;
    std::cout << "Heroes in the Team: " << team->getHeroCount() << std::endl;
    // The team's `displayCaptainInfo` will report which hero is captain; avoid
    // accessing `getHeroes()` here because some Team implementations use an
    // internal array and `getHeroes()` may be null.
}

void Captain::assignCaptain(Hero hero, Team *team)
{
    
}
