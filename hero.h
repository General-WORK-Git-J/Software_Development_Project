#pragma once

#include <iostream>
#include <string>

using namespace std;

class Hero {
    
private:

string heroName;
float health;
int attack;
string weakness;
int heroCount = 0;

public:

Hero();
Hero(string n);
Hero(string n, float health);
Hero(string n, float h, int a, string w);

void setHeroName(string n){ heroName = n;}
string getHeroName(){return heroName;}

void setHealth(float h){ health = h;}
float getHealth(){return health;}

void setAttack(int a){ attack = a;}
int getAttack(){return attack;};

void setWeakness(string w){ weakness = w;}
string getWeakness(){return weakness;};

void displayHeroInfo();
};

Hero::Hero(){
    heroName = "Unknown Hero";
    health = 100.0;
    attack = 10;
    weakness = "None";
    heroCount++;
}