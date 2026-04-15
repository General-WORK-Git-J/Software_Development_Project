#ifndef TEAM_SYSTEM_H
#define TEAM_SYSTEM_H
#include <iostream>
#include <string>
#include <vector>

#include "../Header_Files/team_reader.h"

using std::string;
using std::vector;


class TeamSystem {
private: 

// Container for teams
    vector<Squad> teams;

public:

// Constructors
    TeamSystem() = default;

// Load teams from a file
    void loadFromFile(const string & filename);
    void saveToFile(const string & filename);
    void addTeam(const Squad & teamName);
    void addingTeam(const string & teamName);
};

#endif