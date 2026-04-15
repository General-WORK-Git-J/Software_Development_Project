/* Implementation: Hero
   Constructors and basic behavior for `Hero`. Each constructor initializes
   fields used throughout the system. Persistence is handled at higher levels
   (e.g., Admin/Team) where heroes are written to disk in a simple text format.
*/

#include "../Header_Files/hero.h"
#include "../Header_Files/captain.h"
#include "../Header_Files/team.h"

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
