/*  
    Implementation file for the Hero class, including constructors and member functions,
    which defines the properties of hero characters in our Hero-Agency-Management project.
*/

#include "hero.h"
#include "captain.h"
#include "team.h"

// Constructors
Hero::Hero()
{

    
}

// Parameterized constructors
Hero::Hero(string n)
{

}

// Parameterized constructors
Hero::Hero(string n, int h)
{

}

// Parameterized constructors
Hero::Hero(string n, int h, int a)
{
    
}

// Parameterized constructors
Hero::Hero(string n, int h, int a, string w)
{
    heroName = n;
    health = h;
    attack = a;
    weakness = w;
    captainStatus = false;
    isAlive = true;
    heroCount++;
}

Hero::Hero(string n, int h, int a, string w, bool s)
{
    heroName = n;
    health = h;
    attack = a;
    weakness = w;
    captainStatus = s;
    isAlive = true;
    heroCount++;
}

Hero::Hero(string n, int h, int a, string w, bool s, bool stat)
{
    heroName = n;
    health = h;
    attack = a;
    weakness = w;
    captainStatus = s;
    isAlive = stat;
    heroCount++;
};
