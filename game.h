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
	K_T,
	K_BACKSPACE,
	K_ENTER,
    K_ESCAPE,
    K_COUNTbv
};

enum stage
{
	intro,
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
	end_survivors,
	end_infectants,
	COOP_stage,
	COOP_end,
    infection,
	TUTORIAL,
    //init states
    INIT_intro,
	INIT_MainMenu,
	INIT_stage_survival,
	INIT_PVP_stage1,
	INIT_transition,
	INIT_PVP_stage2,
	INIT_end,
	INIT_end2,
	INIT_countPVP1,
	INIT_countPVP2,
	INIT_countSurvival,
	INIT_countCOOP,
	INIT_countInfection,
	INIT_end_survivors,
	INIT_end_infectants,
	INIT_COOP_stage,
	INIT_COOP_end,
    INIT_infection,
    INIT_statecount,
	INIT_TUTORIAL,
	credit,

	MAX_STATE
	
};


void init();                // initialize your variables, allocate memory, etc
// init function for different states
void init_MainMenu(stage changeState);
void init_PVP_stage1(stage changeState);
void init_PVP_stage2(stage changeState);
void init_countdown321(stage changeState);

void getInput();            // get input from player
void update(double dt,stage state);     // update the game and the state of the game
void update2(double dt);
void render(stage state);              // renders the current state of the game to the console
void shutdown();   // do clean up, free memory
double timer(double& seconds);

void moveCharacter(stage state);       // moves the character, collision detection, physics, etc
void menu_keys();
void moveCharacter_PVP_stage1();
void transition_key();
void moveCharacter_PVP_stage2();
void end_page_key();

void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderMap();           // renders the map to the buffer first
void renderMap2();           
void render_end();
void render_end2();
void render_end_survivors();
void render_end_infectants();
void render_transition();
void renderMainMenu();
void renderCreditPage();
void renderCharacter();		// renders the character into the buffer
void rendercountdown321(stage changeState);
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void ghostAndPlayerCollision(COORD &ene , COORD &p1);
bool PlayerAndCoinCollision(COORD location);
void teleport(COORD& a, COORD b, COORD c);

#endif // _GAME_H