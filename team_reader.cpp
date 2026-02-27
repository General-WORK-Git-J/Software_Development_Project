#include "team_reader.h"
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::cerr;

vector<Squad> loadSquad(const string & filename) {
    vector<Squad> squads;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return squads; // Return empty vector on failure
    }

    while (true){
        Squad squad;
        if (!getline(file, squad.text)) {
            break; // End of file or error
        }

        int optionsCount;
        if (!(file >> optionsCount)) {
            cerr << "Error reading options count for squad: " << squad.text << endl;
            break; // Error reading options count
        }
        file.ignore(); // Ignore the rest of the line

        if (optionsCount<=0) break;


        squad.options.clear();
        for (int i = 0; i < optionsCount; ++i) {
            string option;
            if (!getline(file, option)) {
                cerr << "Error reading option " << i + 1 << " for squad: " << squad.text << endl;
                break; // Error reading option
                squads.push_back(squad);
            }
        }   

        
        string separator;
        if (!getline(file, separator) || separator != "----") {
            cerr << "Error reading separator after squad: " << squad.text << endl;
            break; // Error reading separator
        }
    }
    return squads;
}