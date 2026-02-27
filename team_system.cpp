#include "team_system.h"
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

void TeamSystem::loadFromFile(const string & filename) {
    
    teams = loadSquad(filename);
}

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

void TeamSystem::addTeam(const Squad & team) {
    teams.push_back(team);
}

void TeamSystem::addingTeam(const string & filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for appending: " << filename << endl;
        return;
    }

    Squad newTeam;
    newTeam.text = filename;

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

teams.push_back(newTeam);
}