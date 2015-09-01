#ifndef _SETTINGS_H
#define _SETTINGS_H

#include "Framework/console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

extern int Lives;
extern int LivesStore;
extern int LivesStore2;
extern int RespawnRate;
extern int RespawnTF;
extern int SpawnRate;
extern int MaxGhostCount;
extern int GhostSpeed;
void moveCharacter_settings();
void moveCharacter_settings_PVP();
void moveCharacter_settings_Survival();
void moveCharacter_settings_Infection();
void moveCharacter_settings_COOP();


#endif

