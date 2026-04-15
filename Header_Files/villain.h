#pragma once 

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class Villain {

private:
    
// Villain properties
    int bounty;
    int dangerLevel;
    string weakness;

public:

//getters
    int getBounty() { return bounty; }
    int getDangerLevel() { return dangerLevel; }
    string getWeakness() { return weakness; }

//setters
    void setBounty(int b) { bounty = b; }
    void setDangerLevel(int d) { dangerLevel = d; }
    void setWeakness(string w) { weakness = w; }

// Constructors
    Villain();
    Villain(int b, int d, string w);

};
