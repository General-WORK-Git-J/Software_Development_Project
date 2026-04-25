/* Hero class
   Represents an individual hero with attributes such as name, health, attack,
   weakness and status flags. Used by `Team` and higher-level systems.
*/

#ifndef HERO_H
#define HERO_H
#include <vector>
#include <iostream>
#include <string>

using  std::string;
using std::vector;

// Hero class definition
class Hero {
    
private:

    string heroName;
    int health;
    int attack;
    string weakness;
    int heroCount;
    bool captainStatus;
    bool isAlive;

public:

//Getters
    string getHeroName() const {return heroName;}
    int getHealth() const {return health;}
    int getAttack() const {return attack;}
    string getWeakness() const {return weakness;}
    bool getCaptainStatus() const {return captainStatus;}
    bool getAlive() const {return isAlive;}

//Setters
    void setHeroName(string n) { heroName = n;}
    void setHealth(int h) {health = h;}
    void setAttack(int a) {attack = a;}
    void setWeakness(string w) {weakness = w;}
    void setCaptainStatus(bool s) {captainStatus = s;}
    void setAlive(bool alive) {isAlive = alive;}

//General

 //allows heroes to be sorted alphabetically using operator
    bool operator<(const Hero& other) const { return heroName < other.heroName; }

// Constructors
    Hero();
    Hero(string n);
    Hero(string n, int h);
    Hero(string n, int h, int a);
    Hero(string n, int h, int a, string w);
    Hero(string n, int h, int a, string w, bool s);
    Hero(string n, int h, int a, string w, bool s, bool stat);
};

#endif