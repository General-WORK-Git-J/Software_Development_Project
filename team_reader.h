#ifndef TEAM_READER_H
#define TEAM_READER_H
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


struct Squad {
    string text;
    vector<string> options;
 // Add more fields as needed   
};

vector<Squad> loadSquad(const string & filename);


#endif