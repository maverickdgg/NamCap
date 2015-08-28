#ifndef _SURVIVAL_H
#define _SURVIVAL_H


#include "Framework\timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include "game.h"
extern CStopWatch g_timer;
extern bool g_bQuitGame;

struct SurvivalAI{
	COORD ghosts;
};

void init_survival(stage changeState);
void moveCharacter_survival();
void renderMapSurvival();
void renderCharacterSurvival();
void render_end2();

#endif