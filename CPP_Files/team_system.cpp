#include "../Header_Files/team_system.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <ios>

using std::string;
using std::vector;
using std::ofstream;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::ios;

void TeamSystem::sortTeamsByName() {
    std::sort(teams.begin(), teams.end(),
        [](const Squad & left, const Squad & right) {
            return left.text < right.text;
        });
}

// Load teams from a file into the TeamSystem's `teams` container.
// This delegates to `loadSquad` which reads a simple squad file format.
void TeamSystem::loadFromFile(const string & filename) {
    teams.clear();
    for (const Squad & team : loadSquad(filename)) {
        addTeam(team);
    }
}

// Save teams to a file
void TeamSystem::saveToFile(const string & filename) {
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& team : teams) {
        file << team.text << std::endl;
        file << team.options.size() << std::endl; 
        for (const auto& option : team.options) 
            file << option << std::endl;
        file << "----" << std::endl;
    }
}

// Add a team to the system
void TeamSystem::addTeam(const Squad & team) {
    if (team.text.empty()) {
        throw TeamSystemException("Team name cannot be empty.");
    }

    if (findTeam(team.text) != nullptr) {
        throw TeamSystemException("Team already exists: " + team.text);
    }

    teams.push_back(team);
    sortTeamsByName();
}

Squad* TeamSystem::findTeam(const string & teamName) {
    auto it = std::find_if(teams.begin(), teams.end(),
        [&teamName](const Squad &team) {
            return team.text == teamName;
        });

    if (it == teams.end()) {
        return nullptr;
    }

    return &(*it);
}

const Squad* TeamSystem::findTeam(const string & teamName) const {
    auto it = std::find_if(teams.begin(), teams.end(),
        [&teamName](const Squad &team) {
            return team.text == teamName;
        });

    if (it == teams.end()) {
        return nullptr;
    }

    return &(*it);
}

// Interactive function to add a team by prompting the user for input
void TeamSystem::addingTeam(const string & filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for appending: " << filename << endl;
        return;
    }

    Squad newTeam;

    cout << "Enter the team name: ";
    getline(cin, newTeam.text);

    int optionsCount;
    cout << "Enter the number of options for the team: ";
    cin >> optionsCount;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    for (int i = 0; i < optionsCount; ++i) {
        string option;
        cout << "Enter option " << i + 1 << ": ";
        getline(cin, option);
        newTeam.options.push_back(option);
    }

    addTeam(newTeam);

    file << newTeam.text << endl;
    file << newTeam.options.size() << endl;
    for (const string & option : newTeam.options) {
        file << option << endl;
    }
    file << "----" << endl;
}