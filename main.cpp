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
short sCountdown[21][15];
extern COORD monster1;
extern int score;
extern int score2;
extern Console console;

//function declarations
void stage_infection();
void mainMenu();
void Survival();
void stage_1( void );
void stage_transition();
void stage_2();
void state_end();

void state_end2();
void Count3();
void Count2();
void Count1();
void coop();
stage state=menu;



// TODO:
// Bug in waitUnitil. it waits for the time from getElapsedTime to waitUntil, but should be insignificant.

// main function - starting function
int main( void )
{
    switch(state){
    case menu:mainMenu();
	case count3:Count3();
	case count2:Count2();
	case count1:Count1();
	case stage_survival:Survival();
    case PVP_stage1:stage_1();
    case transition: stage_transition();
    case PVP_stage2:stage_2();
    case infection:stage_infection();
    case end:state_end();
	case end2:state_end2();
	case COOP_stage:coop();
    }
    shutdown();  // do clean up, if any. free memory.
	return 0;
}

//--------------------------------------------------------------
// Purpose	: This main loop calls functions to get input, 
//			update and render the game at a specific frame rate
// Input	: void
// Output	: void
//--------------------------------------------------------------
void mainMenu()
{
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state);
    while (state==menu)      // run this loop until user wants to quit 
	{    
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
		render(state);                   // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.

}

void Survival()
{
	g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state);  
    while (state==stage_survival)      // run this loop until user wants to quit 
	{   
		   
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
        render(state);                      // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.
}

void stage_1( void )
{
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state); 
    while (state==PVP_stage1)      // run this loop until user wants to quit 
	{       
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
        render(state);                      // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.

}

void stage_transition(){
        g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
        init(state); 
		system ("mode 80,30");
            while(state==transition){ 
            getInput();
            update(g_Timer.getElapsedTime());   // update the game
            render(state);                            // render the graphics output to screen
            g_Timer.waitUntil(gc_uFrameTime);
        }
}

void stage_2(){
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
        init(state); 
        while (state==PVP_stage2){
            getInput();
            update(g_Timer.getElapsedTime());   // update the game
            render(state);                           // render the graphics output to screen
            g_Timer.waitUntil(gc_uFrameTime);
        }
            shutdown();  // do clean up, if any. free memory.
}

void stage_infection(){
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
        init(state); 
            while(state==infection){  
            getInput();
            update_infection(g_Timer.getElapsedTime());   // update the game
            render(state);                          // render the graphics output to screen
            g_Timer.waitUntil(gc_uFrameTime);
        }
}

void state_end(){
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
        init(state); 
            while(state==end){  
            getInput();
            update2(g_Timer.getElapsedTime());   // update the game
            render(state);                          // render the graphics output to screen
            g_Timer.waitUntil(gc_uFrameTime);
        }
}

void state_end2(){
        init(state); 
            while(state==end2){  
            getInput();
            update2(g_Timer.getElapsedTime());   // update the game
            render(state);                          // render the graphics output to screen
            g_Timer.waitUntil(gc_uFrameTime);
        }
}

void Count3()
{
	g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
	init(state); 
    while (state==count3)      // run this loop until user wants to quit 
	{    
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
		render(state);                   // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.
}

void Count2()
{
	g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state);   
    while (state==count2)      // run this loop until user wants to quit 
	{    
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
		render(state);                   // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.
}

void Count1()
{
	g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state);   
    while (state==count1)      // run this loop until user wants to quit 
	{    
        getInput();                         // get keyboard input
        update(g_Timer.getElapsedTime());   // update the game
		render(state);                   // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.
}

void coop( void )
{
    g_Timer.startTimer();   // Start timer to calculate how long it takes to render this frame
    system ("mode 80,30");
    init(state); 
    while (state==COOP_stage)      // run this loop until user wants to quit 
	{       
        getInput();                         // get keyboard input
        updateCOOP(g_Timer.getElapsedTime());   // update the game
        render(state);                      // render the graphics output to screen
        g_Timer.waitUntil(gc_uFrameTime);   // Frame rate limiter. Limits each frame to a specified time in ms.      
	} 
        shutdown();  // do clean up, if any. free memory.

}