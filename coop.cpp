#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "map.h"
#include "coop.h"
#include <windows.h>

extern CStopWatch g_Timer;	
extern Console console;
extern COORD charLocation;
extern COORD charLocation2;
extern COORD tp1;
extern COORD tp2;
extern COORD ghost1;
extern COORD ghost2;
extern COORD ghost3;
extern int	g_iMod = 1;
extern int	g_iCol = 1;
bool death = false;
bool p1die = false;
bool p2die = false;
extern stage state;
extern double elapsedTime; 
extern double deltaTime;
extern double coutndwodntiemr;
double counter=10;
void renderHelp();
extern int score;
extern int score2;



void eneXp1Coop(COORD &ene , COORD &p1)
{
	SHORT x = 38;
	SHORT y = 20;
	SHORT * k = &x;
	SHORT * t = &y;

	if(ene.Y == p1.Y && ene.X == p1.X)
	{
		death = true;
		p1die = true;
		counter=7;
	}
	if(death == true)
	{
		if(timer(counter) < 0)
		{
			state = COOP_end;
		}
	}
	else if(death == false)
	{
		counter = 10;
	}
}

void eneXp2Coop(COORD &ene , COORD &p2)
{
	SHORT x = 38;
	SHORT y = 20;
	SHORT * k = &x;
	SHORT * t = &y;

	if(ene.Y == p2.Y && ene.X == p2.X)
	{
		death = true;
		p2die = true;
	}
	if(death == true)
	{
		if(timer < 0)
		{
			state = COOP_end;
		}
	}
	else if(death == false)
	{
		counter = 10;
	}
}

void coopP1xP2(COORD &p1 , COORD &p2)
{
	if(death == true)
	{
		if(p2.Y == p1.Y && p2.X == p1.X)
		{
			death = false;
			p1die = false;
			p2die = false;
		}
	}
	if(p1die && p2die && death == true)
	{
		state = COOP_end;
	}
}

void renderCoopCharacter()
{
	console.writeToBuffer(charLocation, (char)g_iMod, 0x0C+g_iCol);
    console.writeToBuffer(ghost1,232,0x0B);
    console.writeToBuffer(ghost2,232,0x0B);
    console.writeToBuffer(ghost3,232,0x0B);
    if(g_iMod > 6)
	{
		g_iMod = 1;
	}
	if(g_iCol > 6)
	{
		g_iCol = 1;
	}
	eneXp1Coop(ghost1,charLocation);
    eneXp1Coop(ghost2,charLocation);
    eneXp1Coop(ghost3,charLocation);
	eneXp2Coop(ghost1,charLocation2);
    eneXp2Coop(ghost2,charLocation2);
    eneXp2Coop(ghost3,charLocation2);
	coopP1xP2(charLocation, charLocation2);
	p1Xcoin(charLocation);
	p1Xcoin(charLocation2);
	console.writeToBuffer(charLocation2, 148, 0x0C);
	renderHelp();
}

void renderHelp()
{
	if(p1die == true)
	{
		console.writeToBuffer(charLocation.X + 1,charLocation.Y + 1,"I DIE I DIE", 0x0C + counter);
	}
	if(p2die == true)
	{
		console.writeToBuffer(charLocation.X + 1,charLocation2.Y + 1,"I DIE I DIE", 0x0C + counter);
	}
}

void updateCOOP(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;
    //processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();// moves the character, collision detection, physics, etc

    // sound can be played here too.
}