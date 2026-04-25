#include "../Header_Files/menu.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <shellapi.h>


using std::cin;
using std::cout;
using std::endl;
using std::getline;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";
const string CYAN = "\033[36m";

// NEW CODE: prints a smaller main menu so the top level is less cramped.
void showMainMenu() {
    cout << "\n" << CYAN << "========== MAIN MENU ==========" << RESET << endl
         << " (1) View Teams" << endl
         << " (2) Team Management" << endl
         << " (3) Hero Management" << endl
         << " (4) Save State" << endl
         << " (5) Load State" << endl
         << " (6) Help" << endl
         << " (7) Exit" << endl
         << "-> ";
}

// NEW CODE: prints the team management submenu.
void showTeamManagementMenu() {
    cout << "\n" << CYAN << "====== TEAM MANAGEMENT ======" << RESET << endl
         << " (1) Create Team" << endl
         << " (2) Rename Team" << endl
         << " (3) Delete Team" << endl
         << " (4) Sort Teams A-Z" << endl
         << " (5) Return" << endl
         << "-> ";
}

// NEW CODE: prints the hero management submenu.
void showHeroManagementMenu() {
    cout << "\n" << CYAN << "====== HERO MANAGEMENT ======" << RESET << endl
         << " (1) Add Hero To Team" << endl
         << " (2) Delete Hero From Team" << endl
         << " (3) Remove Captain Status" << endl
         << " (4) Sort Heroes In Team A-Z" << endl
         << " (5) View Full Team Info" << endl
         << " (6) Return" << endl
         << "-> ";
}

// NEW CODE: helper that prints team numbers and names only.
static void printTeamNameList(const std::vector<Team>& teams) {
    for (std::size_t i = 0; i < teams.size(); ++i) {
        cout << "[" << (i + 1) << "] " << teams[i].getTeamName() << endl;
    }
}

// NEW CODE: helper that lets the user pick a team and returns the vector index.
static bool selectTeamIndex(const std::vector<Team>& teams, std::size_t& selectedIndex, const string& promptText) {
    if (teams.empty()) {
        cout << RED << "No teams available." << endl << RESET;
        return false;
    }

    cout << "==============================" << endl;
    cout << "        AVAILABLE TEAMS       " << endl;
    cout << "==============================" << endl;
    printTeamNameList(teams);
    cout << "[0] Return" << endl;
    cout << "------------------------------" << endl;

    std::size_t displayedIndex = 0;
    cout << promptText;

    if (!(cin >> displayedIndex)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << "Invalid input." << endl << RESET;
        return false;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (displayedIndex == 0) {
        return false;
    }

    if (displayedIndex > teams.size()) {
        cout << RED << "Invalid team number." << endl << RESET;
        return false;
    }

    selectedIndex = displayedIndex - 1;
    return true;
}

// NEW CODE: list only team number and team name, then let the user choose one team to view.
void listTeamsFromMenu(const std::vector<Team>& teams) {
    std::size_t selectedIndex = 0;

    if (!selectTeamIndex(teams, selectedIndex, "Enter team number to view: ")) {
        return;
    }

    const Team& selectedTeam = teams[selectedIndex];

    cout << "\n==============================" << endl;
    cout << "        TEAM DETAILS          " << endl;
    cout << "==============================" << endl;
    selectedTeam.displayTeamInfo();
    selectedTeam.displayCaptainInfo();
    cout << "==============================" << endl;
}

// NEW CODE: keeps team selection consistent with the numbers shown in the list menu.
bool addHeroToTeamFromMenu(std::vector<Team>& teams) {
    std::size_t realIndex = 0;

    if (!selectTeamIndex(teams, realIndex, "Enter team number: ")) {
        return false;
    }

    std::string name;
    int health = 0;
    int attack = 0;
    std::string weakness;
    char isCap = 'n';

    cout << "Hero name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << RED << "Hero name cannot be empty." << endl << RESET;
        return false;
    }

    cout << "Health: ";
    if (!(cin >> health)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << "Invalid health value." << endl << RESET;
        return false;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Attack: ";
    if (!(cin >> attack)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << "Invalid attack value." << endl << RESET;
        return false;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Weakness: ";
    getline(cin, weakness);

    cout << "Is captain? (y/n): ";
    cin >> isCap;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Hero h(name, health, attack, weakness, (isCap == 'y' || isCap == 'Y'), true);
    teams[realIndex].addHero(h);
    cout << GREEN << "Hero added." << endl << RESET;
    return true;
}

// NEW CODE: implements team creation from the team submenu.
bool createTeamFromMenu(std::vector<Team>& teams) {
    std::string teamName;

    cout << "Enter team name: ";
    getline(cin, teamName);

    if (teamName.empty()) {
        cout << RED << "Team name cannot be empty." << endl << RESET;
        return false;
    }

    for (std::size_t i = 0; i < teams.size(); ++i) {
        if (teams[i].getTeamName() == teamName) {
            cout << RED << "A team with that name already exists." << endl << RESET;
            return false;
        }
    }

    Team newTeam(teamName);
    teams.push_back(newTeam);
    cout << GREEN << "Team created successfully." << endl << RESET;
    return true;
}

// NEW CODE: renames an existing team.
bool renameTeamFromMenu(std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number to rename: ")) {
        return false;
    }

    string newName;
    cout << "Enter new team name: ";
    getline(cin, newName);

    if (newName.empty()) {
        cout << RED << "Team name cannot be empty." << endl << RESET;
        return false;
    }

    for (std::size_t i = 0; i < teams.size(); ++i) {
        if (i != teamIndex && teams[i].getTeamName() == newName) {
            cout << RED << "A team with that name already exists." << endl << RESET;
            return false;
        }
    }

    teams[teamIndex].setTeamName(newName);
    cout << GREEN << "Team renamed successfully." << endl << RESET;
    return true;
}

// NEW CODE: deletes a team using the same displayed numbering as the list menu.
bool deleteTeamFromMenu(std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number to delete: ")) {
        return false;
    }

    const std::string deletedName = teams[teamIndex].getTeamName();
    teams.erase(teams.begin() + teamIndex);
    cout << GREEN << "Deleted team: " << deletedName << endl << RESET;
    return true;
}

// NEW CODE: sorts teams alphabetically using Team::operator<.
bool sortTeamsFromMenu(std::vector<Team>& teams) {
    if (teams.empty()) {
        cout << RED << "No teams available." << endl << RESET;
        return false;
    }

    std::sort(teams.begin(), teams.end());
    cout << GREEN << "Teams sorted alphabetically." << endl << RESET;
    return true;
}

// NEW CODE: deletes a hero from a chosen team by hero name.
bool deleteHeroFromTeamFromMenu(std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number: ")) {
        return false;
    }

    Team &selectedTeam = teams[teamIndex];

    if (selectedTeam.getHeroCount() == 0) {
        cout << RED << "That team has no heroes to delete." << endl << RESET;
        return false;
    }

    cout << "Heroes in " << selectedTeam.getTeamName() << ":" << endl;
    const Hero* heroes = selectedTeam.getHeroes();

    for (int i = 0; i < selectedTeam.getHeroCount(); ++i) {
        cout << " - " << heroes[i].getHeroName() << endl;
    }

    std::string heroName;
    cout << "Enter hero name to delete: ";
    getline(cin, heroName);

    if (heroName.empty()) {
        cout << RED << "Hero name cannot be empty." << endl << RESET;
        return false;
    }

    if (!selectedTeam.removeHeroByName(heroName)) {
        cout << RED << "Hero not found in that team." << endl << RESET;
        return false;
    }

    cout << GREEN << "Hero deleted from team." << endl << RESET;
    return true;
}

// NEW CODE: removes captain status from a selected hero.
bool removeCaptainFromHeroFromMenu(std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number: ")) {
        return false;
    }

    Team &selectedTeam = teams[teamIndex];

    if (selectedTeam.getHeroCount() == 0) {
        cout << RED << "That team has no heroes." << endl << RESET;
        return false;
    }

    cout << "Heroes in " << selectedTeam.getTeamName() << ":" << endl;
    const Hero* heroes = selectedTeam.getHeroes();

    for (int i = 0; i < selectedTeam.getHeroCount(); ++i) {
        cout << " - " << heroes[i].getHeroName();
        if (heroes[i].getCaptainStatus()) {
            cout << " (Captain)";
        }
        cout << endl;
    }

    std::string heroName;
    cout << "Enter hero name to remove captain status from: ";
    getline(cin, heroName);

    if (heroName.empty()) {
        cout << RED << "Hero name cannot be empty." << endl << RESET;
        return false;
    }

    Hero* hero = selectedTeam.findHero(heroName);
    if (hero == nullptr) {
        cout << RED << "Hero not found in that team." << endl << RESET;
        return false;
    }

    if (!hero->getCaptainStatus()) {
        cout << RED << "That hero is not currently a captain." << endl << RESET;
        return false;
    }

    selectedTeam.removeCaptainStatusFromHero(heroName);
    cout << GREEN << "Captain status removed." << endl << RESET;
    return true;
}

// NEW CODE: sorts heroes in one selected team alphabetically using Hero::operator<.
bool sortHeroesInTeamFromMenu(std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number: ")) {
        return false;
    }

    if (teams[teamIndex].getHeroCount() == 0) {
        cout << RED << "That team has no heroes to sort." << endl << RESET;
        return false;
    }

    teams[teamIndex].sortHeroesAlphabetically();
    cout << GREEN << "Heroes sorted alphabetically." << endl << RESET;
    return true;
}

// NEW CODE: displays full team info for one selected team.
void viewFullTeamInfoFromMenu(const std::vector<Team>& teams) {
    std::size_t teamIndex = 0;

    if (!selectTeamIndex(teams, teamIndex, "Enter team number to view: ")) {
        return;
    }

    cout << "\n==============================" << endl;
    cout << "       FULL TEAM DETAILS      " << endl;
    cout << "==============================" << endl;
    teams[teamIndex].displayFullTeamInfo();
    cout << "==============================" << endl;
}

// NEW CODE: opens the README file in the default application on Windows.
void openReadMeFromMenu() {
    HINSTANCE result = ShellExecuteA(
        NULL,
        "open",
        "notepad.exe",
        "..\\README.md",
        NULL,
        SW_SHOWNORMAL
    );

    if ((INT_PTR)result > 32) {
        cout << GREEN << "Success: README opened." << RESET << endl;
    }
    else {
        cout << RED << "Error: README could not be opened." << RESET << endl;
    }
}
