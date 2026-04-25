#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

#include "team.h"

using std::string;
using std::vector;

// NEW CODE: shared menu display functions used by main.cpp.
void showMainMenu();
void showTeamManagementMenu();
void showHeroManagementMenu();

// NEW CODE: list team names and let the user choose one team to inspect.
void listTeamsFromMenu(const vector<Team>& teams);

// NEW CODE: team management helpers.
bool createTeamFromMenu(vector<Team>& teams);
bool renameTeamFromMenu(vector<Team>& teams);
bool deleteTeamFromMenu(vector<Team>& teams);
bool sortTeamsFromMenu(vector<Team>& teams);

// NEW CODE: hero management helpers.
bool addHeroToTeamFromMenu(vector<Team>& teams);
bool deleteHeroFromTeamFromMenu(vector<Team>& teams);
bool removeCaptainFromHeroFromMenu(vector<Team>& teams);
bool sortHeroesInTeamFromMenu(vector<Team>& teams);
void viewFullTeamInfoFromMenu(const vector<Team>& teams);

// NEW CODE: opens the project README in the default Windows application.
void openReadMeFromMenu();

#endif
