#ifndef _SURVIVAL_H
#define _SURVIVAL_H


#include "Framework\timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
extern CStopWatch g_timer;
extern bool g_bQuitGame;

void survivalControls();
void updateSurvival(double dt);
void renderMapSurvival();
void renderCharacterSurvival();
void render_end2();

#endif