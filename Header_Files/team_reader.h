#ifndef TEAM_READER_H
#define TEAM_READER_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Structure to represent a squad/team with its text and options
struct Squad {
    string text;
    vector<string> options;
 // Add more fields as needed   
};

// Function to load squads from a file
vector<Squad> loadSquad(const string & filename);

#endif