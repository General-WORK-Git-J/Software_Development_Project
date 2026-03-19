#include "admin.h"
#include "hero.h"
#include "team.h"
#include "captain.h"

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;  
using std::ofstream;
using std::ios;
using std::cerr;
using std::cin;
using std::streamsize;
using std::getline;
using std::ofstream;
using std::ifstream;


//===================================================================================
void Admin::createHero(string name, int health, int attack, string weakness) {
    Hero newHero(name, health, attack, weakness);
    cout << "Hero created: " << newHero.getHeroName() << endl;
}

//create a team with the given name
void Admin::createTeam(string teamName) {
    Team newTeam(teamName);
    cout << "Team created: " << newTeam.getTeamName() << endl;
}

//assign a hero as the captain of a team
void Admin::assignCaptain(Hero hero, Team team) {
    //Captain newCaptain(hero.getHeroName(), &team);
    //cout << "Captain " << newCaptain.getCaptainName() << " assigned to team " << team.getTeamName() << endl;
}

//display information about a team, including its heroes and captain
void Admin::displayTeamInfo(Team team) {
    cout << "Team Name: " << team.getTeamName() << endl;
    cout << "Heroes in the team:" << endl;
    for (int i = 0; i < team.getHeroCount(); i++) {
        Hero hero = team.getHeroes()[i];
        cout << "- " << hero.getHeroName() << " (Health: " << hero.getHealth() 
             << ", Attack: " << hero.getAttack() 
             << ", Weakness: " << hero.getWeakness() 
             << ", Captain: " << (hero.getCaptainStatus() ? "Yes" : "No") 
             << ", Alive: " << (hero.getAlive() ? "Yes" : "No") 
             << ")" << endl;
    }
}