/*  
    Main file for the Hero-Agency-Management project,
    which demonstrates the creation and management of heroes, teams, and captains.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "hero.h"
#include "team.h"
#include "captain.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;

// Main function to demonstrate the functionality of the Hero-Agency-Management system
int main() {
    cout << "PROGRAM START" << endl;

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
    Hero hero18("Uriel", 100, 100, "None");
    Hero hero19("Kratos", 150, 150, "Rage");
    Hero hero20("Icarus", 60, 40, "The Sun");
    
    // Create a team and add heroes to it
    Team justiceLeague("Justice League");
    // assign captain status before adding so the team's copy reflects it
    hero1.setCaptainStatus(true);
    justiceLeague.addHero(hero1);
    justiceLeague.addHero(hero2);
    justiceLeague.addHero(hero3);
    justiceLeague.addHero(hero4);
    justiceLeague.addHero(hero5);
    justiceLeague.addHero(hero6);

    // Create another team and add heroes to it
    Team animeHeroes("Anime Heroes");
    // Make Luffy the captain of animeHeroes
    hero10.setCaptainStatus(true);
    animeHeroes.addHero(hero7);     
    animeHeroes.addHero(hero8);
    animeHeroes.addHero(hero9);
    animeHeroes.addHero(hero10);
    animeHeroes.addHero(hero11);
    animeHeroes.addHero(hero12);
    animeHeroes.addHero(hero13);

    // Create captains (store name and team pointer)
    Captain JLcaptain("Superman", &justiceLeague);
    Captain animeCaptain("Luffy", &animeHeroes);

    // put teams in a container for save/load and interactive modification
    vector<Team> teams;
    teams.push_back(justiceLeague);
    teams.push_back(animeHeroes);

    // Simple CLI loop
    bool running = true;
    while (running) {
        cout << "\nMenu: (1) List teams (2) Add hero to team (3) Save state (4) Load state (5) Exit -> ";
        int choice = 0;
        if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cin.ignore(10000, '\n');
        if (choice == 1) {
            for (size_t i = 1; i < teams.size(); ++i) {
                cout << "-- Team [" << i << "] --" << endl;
                teams[i].displayTeamInfo();
                teams[i].displayCaptainInfo();
            }
        } else if (choice == 2) {
            cout << "Enter team index: "; size_t idx; if (!(cin >> idx)) { cin.clear(); cin.ignore(10000,'\n'); continue; }
            cin.ignore(10000,'\n'); if (idx >= teams.size()) { cout << "Invalid index\n"; continue; }
            string name; int health, attack; string weakness; char isCap='n';
            cout << "Hero name: "; getline(cin, name);
            cout << "Health: "; cin >> health; cin.ignore(10000,'\n');
            cout << "Attack: "; cin >> attack; cin.ignore(10000,'\n');
            cout << "Weakness: "; getline(cin, weakness);
            cout << "Is captain? (y/n): "; cin >> isCap; cin.ignore(10000,'\n');
            Hero h(name, health, attack, weakness, (isCap=='y' || isCap=='Y'), true);
            teams[idx].addHero(h);
            cout << "Hero added.\n";
        } else if (choice == 3) {
            string fname; cout << "Save filename: "; getline(cin, fname);
            if (fname.empty()) fname = "teams_state.txt";
            ofstream ofs(fname);
            for (const auto &t : teams) t.save(ofs);
            ofs.close();
            cout << "Saved to " << fname << endl;
        } else if (choice == 4) {
            string fname; cout << "Load filename: "; getline(cin, fname);
            if (fname.empty()) fname = "teams_state.txt";
            ifstream ifs(fname);
            if (!ifs.is_open()) { cout << "Cannot open file\n"; continue; }
            teams.clear();
            while (ifs.peek() != EOF) {
                Team t;
                if (!t.load(ifs)) break;
                teams.push_back(t);
            }
            ifs.close();
            cout << "Loaded " << teams.size() << " teams from " << fname << endl;
        } else if (choice == 5) {
            running = false;
        }
    }

    return 0;
}
