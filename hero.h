/*  Header file for the Hero class, which includes constructors and member functions,
    which defines the properties of hero characters in our Hero-Agency-Management project.
*/

#ifndef HERO_H
#define HERO_H
#include <vector>
#include <iostream>
#include <string>

using  std::string;
using std::vector;

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
    string getHeroName() {return heroName;}
    int getHealth() {return health;}
    int getAttack() {return attack;}
    string getWeakness() {return weakness;}
    bool getCaptainStatus() {return captainStatus;}
    bool getAlive() {return isAlive;}

//Setters
    void setHeroName(string n) { heroName = n;}
    void setHealth(int h) {health = h;}
    void setAttack(int a) {attack = a;}
    void setWeakness(string w) {weakness = w;}
    void setCaptainStatus(bool s) {captainStatus = s;}
    void setAlive(bool alive) {isAlive = alive;}

//General

//Constructors

    Hero::Hero();
    Hero::Hero(string n);
    Hero::Hero(string n, int h);
    Hero::Hero(string n, int h, int a);
    Hero::Hero(string n, int h, int a, string w);
    Hero::Hero(string n, int h, int a, string w, bool s);
    Hero::Hero(string n, int h, int a, string w, bool s, bool stat);
};

#endif