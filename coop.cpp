#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "coop.h"
#include <windows.h>
#include "ai.h"

extern CStopWatch g_Timer;	
extern Console console;
extern bool keyPressed[K_COUNTbv];
extern short sPacMap[21][38];
extern char map2[];

extern const int ciOffsetX;
extern const int ciOffsetY;
extern int g_idirection;
extern int g_idirection2;
extern int g_idirection3;
extern int	g_iChangeMod;
extern int	g_iChangeCol;
extern int	g_iauto;

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
int timeCom;

void init_COOP(){



		elapsedTime = 0.0;
        readfile(sPacMap,map2);

		charLocation.X = 38;
        charLocation.Y = 20;

		charLocation2.X = 38;
        charLocation2.Y = 20;

		ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;
		PlaySound(NULL, 0,0);
		PlaySound(TEXT("pacman_eatfruit.wav"),NULL,SND_LOOP|SND_ASYNC);
}

void moveCharacter_COOP(){
    		if(p1die == false)
		{
			if (keyPressed[K_UP] && charLocation.Y > 0 && wall_up(charLocation)==false)
			{
				//Beep(1440, 30);
				charLocation.Y--;
			}
			if (keyPressed[K_LEFT] && charLocation.X > 0 && wall_left(charLocation)==false)
			{
				//Beep(1440, 30);
				charLocation.X--;
			}
			if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && wall_down(charLocation)==false)
			{
				//Beep(1440, 30);
				charLocation.Y++;
			}
			if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1 && wall_right(charLocation)==false)
			{
				//Beep(1440, 30);
				charLocation.X++;
			}
		}
		if(p2die == false)
		{
			if (keyPressed[K_W] && charLocation2.Y > 0 && wall_up(charLocation2)==false)
			{
				//Beep(1440, 30);
				charLocation2.Y--;
			}
			if (keyPressed[K_A] && charLocation2.X > 0 && wall_left(charLocation2)==false)
			{
				//Beep(1440, 30);
				charLocation2.X--;
			}
			if (keyPressed[K_S] && charLocation2.Y < console.getConsoleSize().Y - 1 && wall_down(charLocation2)==false)
			{
				//Beep(1440, 30);
				charLocation2.Y++;
			}
			if (keyPressed[K_D] && charLocation2.X < console.getConsoleSize().X - 1 && wall_right(charLocation2)==false)
			{
				//Beep(1440, 30);
				charLocation2.X++;
			}
    
			if(keyPressed[K_M])
			{
				g_iChangeMod += 1;
			}
			if(keyPressed[K_N])
			{
				g_iChangeCol += 1;
			} 
		}
    monster(ghost1,g_idirection);
    monster(ghost2,g_idirection2);
    monster(ghost3,g_idirection3);
}

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

void coopWinCon()
{
	timeCom = elapsedTime;
	if(score > 265)
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

void renderEndCondition()
{
	if(score > 265)
	{
		console.writeToBuffer(10,10,"Time Complete:",0x0C);
		console.writeToBuffer(10,15,timeCom,0x0C);
	}
	if(score < 266)
	{
		console.writeToBuffer(10,10,"HAHA you suck at it",0x0C);
	}
}
