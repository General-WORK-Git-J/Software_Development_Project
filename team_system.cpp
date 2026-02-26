#include "team_system.h"
#include <fstream>
#include <iostream>
#include <limits>

using std::string;
using std::vector;

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