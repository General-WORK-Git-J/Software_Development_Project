#include "../Header_Files/admin.h"
#include "../Header_Files/user_system.h"
#include "../Header_Files/hero.h"
#include "../Header_Files/team.h"
#include "../Header_Files/captain.h"

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
// Create a hero and persist to disk. Only users with admin role may create heroes.
// The hero is written to `heroes.txt` as a single '|' delimited line.
void Admin::createHero(string name, int health, int attack, string weakness, UserSystem* userSys) {
    if (!userSys || !userSys->isAdmin()) {
        cerr << "Permission denied: only admins can create heroes." << endl;
        return;
    }

    Hero newHero(name, health, attack, weakness);
    cout << "Hero created: " << newHero.getHeroName() << endl;

    // Persist the hero to a simple text database (append mode).
    std::ofstream file("heroes.txt", std::ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open heroes.txt for writing." << endl;
        return;
    }
    // Format: name|health|attack|weakness|captainStatus|isAlive
    file << newHero.getHeroName() << "|" << newHero.getHealth() << "|" << newHero.getAttack()
         << "|" << newHero.getWeakness() << "|" << (newHero.getCaptainStatus() ? 1 : 0)
         << "|" << (newHero.getAlive() ? 1 : 0) << std::endl;
    file.close();
}

//create a team with the given name
void Admin::createTeam(string teamName, UserSystem* userSys) {
    // Allow admins and basic users to create teams
    if (!userSys) {
        cerr << "Permission denied: no user context provided for team creation." << endl;
        return;
    }
    string role = userSys->getCurrentUserRole();
    if (role != "admin" && role != "user") {
        cerr << "Permission denied: only admin or basic users can create teams." << endl;
        return;
    }

    Team newTeam(teamName);
    cout << "Team created: " << newTeam.getTeamName() << " by " << userSys->getCurrentUser() << endl;

    // Persist the new team using Team::save
    std::ofstream file("teams.txt", std::ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open teams.txt for writing." << endl;
        return;
    }
    newTeam.save(file);
    file.close();
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