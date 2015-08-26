#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
extern CStopWatch g_timer;
extern bool g_bQuitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
	K_W,
	K_S,
	K_A,
	K_D,
	K_M,
	K_N,
	K_ENTER,
    K_ESCAPE,
    K_COUNTbv
};

enum stage
{
	menu,
	stage_survival,
	PVP_stage1,
	transition,
	PVP_stage2,
	end,
	end2,
	countPVP1,
	countPVP2,
	countSurvival,
	countCOOP,
	countInfection,
	//count3,
	//count2,
	//count1,
	COOP_stage,
	COOP_end,
    infection,
    statecount
};


void init();                // initialize your variables, allocate memory, etc
void init(stage state);
void init_PVP_stage1();
void init_PVP_stage2();
void getInput();            // get input from player
void update(double dt,stage state);     // update the game and the state of the game
void update2(double dt);
void render(stage state);              // renders the current state of the game to the console
void updateCOOP(double dt);
void shutdown();   // do clean up, free memory
double timer(double& seconds);

void moveCharacter(stage state);       // moves the character, collision detection, physics, etc
void moveCharacter_menu();
void moveCharacter_PVP_stage1();
void moveCharacter_transition();
void moveCharacter_PVP_stage2();
void moveCharacter_end();

void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderMap();           // renders the map to the buffer first
void renderMap2();           
void render_end();
void render_end2();
void render_transition();
void renderMainMenu();
void renderCharacter();		// renders the character into the buffer
void rendercountdown321(stage changeState);
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void eneXp1(COORD &ene , COORD &p1);
bool p1Xcoin(COORD location);
void teleport(COORD& a, COORD b, COORD c);

#endif // _GAME_H