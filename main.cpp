// This is the main file to hold everthing together

#include "Framework\timer.h"
#include "game.h"
#include "GameUI.h"
#include "Framework\console.h"
#include <Windows.h>
#include "ai.h"
#include "survival.h"
#include "coop.h"
#include "infection.h"

CStopWatch g_Timer;							// Timer function to keep track of time and the frame rate
bool g_bQuitGame = false;					// Set to true if you want to quit the game
const unsigned char gc_ucFPS = 15;				// FPS of this game
const unsigned int gc_uFrameTime = 1000 / gc_ucFPS;	// time for each frame
short sPacMap[21][38];
extern COORD monster1;
extern int score;
extern int score2;
extern Console console;
stage state=INIT_intro;
extern PMAP pacMap;
extern PMAP pacMap2;
extern PMAP pacMap3;
//function declarations
void mainLoop();

// TODO:
// Bug in waitUnitil. it waits for the time from getElapsedTime to waitUntil, but should be insignificant.

// main function - starting function
//Done By Daniel(Leader)
int main( void )
{
    init();      // initialize your variables
    mainLoop();  // main loop
    shutdown();  // do clean up, if any. free memory.
    free_map(pacMap);
	free_map(pacMap2);
	free_map(pacMap3);
    return 0;
}

//--------------------------------------------------------------
// Purpose	: This main loop calls functions to get input, 
//			update and render the game at a specific frame rate
// Input	: void
// Output	: void
//--------------------------------------------------------------

//Done By Daniel(Leader)
void mainLoop()
{
    g_Timer.startTimer();    // Start timer to calculate how long it takes to render this frame
    while (!g_bQuitGame)      // run this loop until user wants to quit 
    {  
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime(),state);   // update the game
        render(state);                // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.  
        
    }    
}