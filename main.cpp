/*  
    Main file for the Hero-Agency-Management project,
    which demonstrates the creation and management of heroes, teams, and captains.
*/

#include <iostream>
#include <string>
#include "hero.h"
#include "team.h"
#include "captain.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

int main() {
    // Create heroes
    Hero hero1("Superman", 100, 50, "Kryptonite");
    Hero hero2("Batman", 80, 30, "Himself");
    Hero hero3("Wonder Woman ", 90, 40, "Ropes");
    Hero hero4("Flash", 70, 35, "Cold");
    Hero hero5("Green Lantern", 85, 45, "Yellow");
    Hero hero6("Aquaman", 75, 25, "Dehydration");
    Hero hero7("Ichigo" , 95, 55, "Plot");
    Hero hero8("Goku", 120, 60, "Powerscalers");
    Hero hero9("Naruto", 85, 40, "Sasuke");
    Hero hero10("Luffy", 80, 45, "The Sea");
    Hero hero11("Frieren", 90.0, 50, "Wakey Wakey");
    Hero hero12("Kiora", 85, 40, "The Heart");
    Hero hero13("Saitama", 100, 100, "Boredom");
    Hero hero14("Captain Underpants", 80, 40, "Snapping fingers");
    Hero hero15("Invincible", 90, 50, "Trains");
    Hero hero16("Joker", 70, 30, "The IRS");
    Hero hero17("Spider-man", 75, 40, "The Writer");

    
    // Create a team and add heroes to it
    Team justiceLeague("Justice League");
    justiceLeague.addHero(hero1);
    justiceLeague.addHero(hero2);
    justiceLeague.addHero(hero3);
    justiceLeague.addHero(hero4);
    justiceLeague.addHero(hero5);
    justiceLeague.addHero(hero6);

    Team animeHeroes("Anime Heroes");
    animeHeroes.addHero(hero7);     
    animeHeroes.addHero(hero8);
    animeHeroes.addHero(hero9);
    animeHeroes.addHero(hero10);
    animeHeroes.addHero(hero11);
    animeHeroes.addHero(hero12);
    animeHeroes.addHero(hero13);

    // Create a captain for the team
//    Captain JLcaptain("Superman", &justiceLeague);
//   Captain animeCaptain("Luffy", &animeHeroes);

    // Display information about the captain and the team
//    JLcaptain.displayCaptainInfo();
    justiceLeague.displayTeamInfo();

    //justiceLeague.displayCaptainInfo();
//    animeCaptain.displayCaptainInfo();
    animeHeroes.displayTeamInfo();
    
    return 0;
}
