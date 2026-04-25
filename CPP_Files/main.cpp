/*  
    Main file for the Hero-Agency-Management project,
    which demonstrates the creation and management of heroes, teams, and captains.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../Header_Files/hero.h"
#include "../Header_Files/team.h"
#include "../Header_Files/captain.h"
#include "../Header_Files/user_system.h"
#include "../Header_Files/menu.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";
const string CYAN = "\033[36m";

// Main function to demonstrate the functionality of the Hero-Agency-Management system
int main() {
    cout << GREEN << "PROGRAM START" << endl << RESET;

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
    Hero hero11("Frieren", 90, 50, "Wakey Wakey");
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

    // NEW CODE: set captain status before adding so the stored team copy keeps it.
    hero1.setCaptainStatus(true);
    justiceLeague.addHero(hero1);
    justiceLeague.addHero(hero2);
    justiceLeague.addHero(hero3);
    justiceLeague.addHero(hero4);
    justiceLeague.addHero(hero5);
    justiceLeague.addHero(hero6);

    // Create another team and add heroes to it
    Team animeHeroes("Anime Heroes");

    // NEW CODE: set captain status before adding so the stored team copy keeps it.
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

    UserSystem userSys;

    // NEW CODE: require login or registration before the main menu opens.
    bool loggedIn = false;
    while (!loggedIn) {
        int startChoice = 0;

        cout << "\nLogin Menu:\n (1) Login\n (2) Register\n (3) Exit\n-> ";

        if (!(cin >> startChoice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        if (startChoice == 1) {
            string username;
            string password;

            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);

            if (userSys.loginUser(username, password)) {
                cout << CYAN << "Logged in as user: " << userSys.getCurrentUser() << endl << RESET;
                loggedIn = true;
            }
            else {
                cout << RED << "Login failed. Try again." << endl << RESET;
            }
        }

        else if (startChoice == 2) {
            string username;
            string password;

            cout << "Choose username: ";
            getline(cin, username);
            cout << "Choose password: ";
            getline(cin, password);

            if (username.empty() || password.empty()) {
                cout << RED << "Username and password cannot be empty." << endl << RESET;
            }
            else if (userSys.registerUser(username, password, "user")) {
                cout << GREEN << "User registered successfully. You can now log in." << endl << RESET;
            }
            else {
                cout << RED << "That username already exists." << endl << RESET;
            }
        }

        else if (startChoice == 3) {
            return 0;
        }
    }

    // NEW CODE: main loop now uses smaller submenus to keep the interface less cramped.
    bool running = true;

    while (running) {
        cout << CYAN << "\nCurrent User: " << userSys.getCurrentUser() << RESET << endl;
        showMainMenu();

        int choice = 0;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 1) {
            listTeamsFromMenu(teams);
        }

        else if (choice == 2) {
            bool teamMenuRunning = true;

            while (teamMenuRunning) {
                showTeamManagementMenu();

                int teamChoice = 0;
                if (!(cin >> teamChoice)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                cin.ignore(10000, '\n');

                if (teamChoice == 1) {
                    createTeamFromMenu(teams);
                }
                else if (teamChoice == 2) {
                    renameTeamFromMenu(teams);
                }
                else if (teamChoice == 3) {
                    deleteTeamFromMenu(teams);
                }
                else if (teamChoice == 4) {
                    sortTeamsFromMenu(teams);
                }
                else if (teamChoice == 5) {
                    teamMenuRunning = false;
                }
            }
        }

        else if (choice == 3) {
            bool heroMenuRunning = true;

            while (heroMenuRunning) {
                showHeroManagementMenu();

                int heroChoice = 0;
                if (!(cin >> heroChoice)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                cin.ignore(10000, '\n');

                if (heroChoice == 1) {
                    addHeroToTeamFromMenu(teams);
                }
                else if (heroChoice == 2) {
                    deleteHeroFromTeamFromMenu(teams);
                }
                else if (heroChoice == 3) {
                    removeCaptainFromHeroFromMenu(teams);
                }
                else if (heroChoice == 4) {
                    sortHeroesInTeamFromMenu(teams);
                }
                else if (heroChoice == 5) {
                    viewFullTeamInfoFromMenu(teams);
                }
                else if (heroChoice == 6) {
                    heroMenuRunning = false;
                }
            }
        }

        else if (choice == 4) {
            string fname;
            cout << "Save filename: ";
            getline(cin, fname);

            if (fname.empty()) fname = "teams_state.txt";

            ofstream ofs(fname);
            for (const auto &t : teams) {
                t.save(ofs);
            }
            ofs.close();
            cout << GREEN << "Saved to " << fname << endl << RESET;
        }

        else if (choice == 5) {
            string fname;
            cout << "Load filename: ";
            getline(cin, fname);

            if (fname.empty()) fname = "teams_state.txt";

            ifstream ifs(fname);
            if (!ifs.is_open()) {
                cout << RED << "Cannot open file." << endl << RESET;
                continue;
            }

            teams.clear();
            while (ifs.peek() != EOF) {
                Team t;
                if (!t.load(ifs)) break;
                teams.push_back(t);
            }
            ifs.close();
            cout << GREEN << "Loaded " << teams.size() << " teams from " << fname << endl << RESET;
        }

        else if (choice == 6) {
            openReadMeFromMenu();
        }

        else if (choice == 7) {
            userSys.logoutUser();
            running = false;
        }
    }

    return 0;
}
