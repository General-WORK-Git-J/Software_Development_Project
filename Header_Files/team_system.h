#ifndef TEAM_SYSTEM_H
#define TEAM_SYSTEM_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../Header_Files/team_reader.h"

using std::string;
using std::vector;

class TeamSystemException : public std::runtime_error {
public:
    explicit TeamSystemException(const string & message)
        : std::runtime_error(message) {}
};

class TeamSystem {
private: 

// Container for teams
    vector<Squad> teams;

    void sortTeamsByName();

public:

// Constructors
    TeamSystem() = default;

// Load teams from a file
    void loadFromFile(const string & filename);
    void saveToFile(const string & filename);
    void addTeam(const Squad & teamName);
    void addingTeam(const string & teamName);
    Squad* findTeam(const string & teamName);
    const Squad* findTeam(const string & teamName) const;
    const vector<Squad>& getTeams() const { return teams; }
    int getTeamCount() const { return static_cast<int>(teams.size()); }
};

#endif