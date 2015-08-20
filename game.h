#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
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
    K_ESCAPE,
    K_COUNTbv
};

enum stage
{
	menu,
	stage1,
	stage2,
	end,
    statecount
};

void eneXp1(COORD &ene , COORD &p1);
bool p1Xcoin(COORD location);
void init();                // initialize your variables, allocate memory, etc
void init2(); 
void init3(); 
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void update2(double dt);
void render();              // renders the current state of the game to the console
void render2();
void render_end();
void shutdown();            // do clean up, free memory

void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderMap();           // renders the map to the buffer first
void renderMap2();           
void renderMap3();
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

#endif // _GAME_H