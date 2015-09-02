#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "coop.h"
#include <windows.h>
#include "ai.h"
#include "map.h"
#include "tutorial.h"

extern CStopWatch g_Timer;	
extern Console console;
extern bool keyPressed[K_COUNTbv];
extern short sPacMap[21][38];
extern char map2[];
extern PMAP pacMap;

extern const int ciOffsetX;
extern const int ciOffsetY;
extern int g_idirection;
extern int g_idirection2;
extern int g_idirection3;
extern int	g_iChangeMod;
extern int	g_iChangeCol;
extern int	g_iauto;

extern COORD player_1;
extern COORD player_2;
extern COORD portal1;
extern COORD portal2;
extern COORD ghost1;
extern COORD ghost2;
extern COORD ghost3;

extern int	g_iMod = 1;
extern int	g_iCol = 1;

bool death = false;
bool player1Die = false;
bool player2Die = false;

extern stage state;
extern double elapsedTime; 
extern double deltaTime;
double counter=10;
void renderCallForHelp();
extern int score;
extern int score2;
int timeCom;


//Done By Victor
void init_COOP(stage changeState)
{

	elapsedTime = 0.0;
    pacMap=load_map(1);
	PlaySound(NULL,0,0);
	PlaySound(TEXT("Zelda Link's Awakening Music - Overworld  Main Theme"),NULL,SND_LOOP | SND_ASYNC);

	player_1.X = 38;
    player_1.Y = 20;

	player_2.X = 38;
    player_2.Y = 20;

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
    state=changeState;
}

//Done By Victor
void init_COOP_end(stage changeState)
{
	elapsedTime = 0.0;
	pacMap=load_map(6);
	PlaySound(NULL, 0,0);
	PlaySound(TEXT("Super Mario Bros. - Game Over Sound Effect.wav"),NULL,SND_LOOP|SND_ASYNC);
    state=changeState;
}
//Done by victor
void moveCharacter_COOP()
{
	//check whether the player die 
	if(player1Die == false)
	{
		//check what keys the player pressed 
		if (keyPressed[K_UP] && player_1.Y > 0 && wall_up(player_1)==false)
		{
			player_1.Y--;
		}
		if (keyPressed[K_LEFT] && player_1.X > 0 && wall_left(player_1)==false)
		{
			player_1.X--;
		}
		if (keyPressed[K_DOWN] && player_1.Y < console.getConsoleSize().Y - 1 && wall_down(player_1)==false)
		{
			player_1.Y++;
		}
		if (keyPressed[K_RIGHT] && player_1.X < console.getConsoleSize().X - 1 && wall_right(player_1)==false)
		{
			player_1.X++;
		}
	}
	//check whether the player die 
	if(player2Die == false)
	{
		//check what keys the player pressed 
		if (keyPressed[K_W] && player_2.Y > 0 && wall_up(player_2)==false)
		{
			player_2.Y--;
		}
		if (keyPressed[K_A] && player_2.X > 0 && wall_left(player_2)==false)
		{
			player_2.X--;
		}
		if (keyPressed[K_S] && player_2.Y < console.getConsoleSize().Y - 1 && wall_down(player_2)==false)
		{
			player_2.Y++;
		}
		if (keyPressed[K_D] && player_2.X < console.getConsoleSize().X - 1 && wall_right(player_2)==false)
		{
			player_2.X++;
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

//Done By Victor
void ghostAndPlayer1CollisionCoop(COORD &ene , COORD &p1)
{
	//check whether the enemy is on the same loction as the player
	if(ene.Y == p1.Y && ene.X == p1.X)
	{
		death = true;
		player1Die = true;
	}
	if(death == true)
	{
		
		if(timer(counter) < 0)
		{
			state = INIT_COOP_end;
		}
	}
	else if(death == false)
	{
		counter = 10;
	}
}

//Done By Victor
void ghostAndPlayer2CollisionCoop(COORD &ene , COORD &p2)
{
	//check whether the enemy is on the same loction as the player
	if(ene.Y == p2.Y && ene.X == p2.X)
	{
		death = true;
		player2Die = true;
	}
	if(death == true)
	{
		if(timer < 0)
		{
			state = INIT_COOP_end;
		}
	}
	else if(death == false)
	{
		counter = 10;
	}
}
	
//Done By Victor
void renderCallForHelp(COORD &p1 , COORD &p2)
{
	//check whether the player die 
	if(death == true)
	{
		if(p2.Y == p1.Y && p2.X == p1.X)
		{
			death = false;
			player1Die = false;
			player2Die = false;
		}
	}
	//if both player die game over 
	if(player1Die && player2Die && death == true)
	{
		state = INIT_COOP_end;
	}
}

//Done By Victor
void coopWinCondition()
{
	timeCom = elapsedTime;
	//player win after this condition met
	if(score >= 326)
	{
		state = INIT_COOP_end;
	}
}

//Done By Victor
void renderCoopCharacter()
{
	console.writeToBuffer(player_1, (char)g_iMod, 0x0C+g_iCol);
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
	ghostAndPlayer1CollisionCoop(ghost1,player_1);
    ghostAndPlayer1CollisionCoop(ghost2,player_1);
    ghostAndPlayer1CollisionCoop(ghost3,player_1);
	ghostAndPlayer2CollisionCoop(ghost1,player_2);
    ghostAndPlayer2CollisionCoop(ghost2,player_2);
    ghostAndPlayer2CollisionCoop(ghost3,player_2);
	renderCallForHelp(player_1, player_2);
	PlayerAndCoinCollision(player_1);
	PlayerAndCoinCollision(player_2);
	console.writeToBuffer(player_2, 148, 0x0C);
	renderCallForHelp();
}

//Done By Victor
void renderCallForHelp()
{
	//player calling for help
	if(player1Die == true)
	{
		console.writeToBuffer(player_1.X + 1,player_1.Y + 1,"I DIE I DIE", 0x0C + counter);
	}
	if(player2Die == true)
	{
		console.writeToBuffer(player_1.X + 1,player_2.Y + 1,"I DIE I DIE", 0x0C + counter);
	}
}

//Done By Victor
void renderEndCondition()
{
	insertmap(pacMap);
	if(score >= 326)
	{
		console.writeToBuffer(10,27,"Time Complete:",0x0C);
		console.writeToBuffer(10,32,timeCom,0x0C);
	}
	if(score <= 325)
	{
		console.writeToBuffer(30,27,"HAHA you suck at it",0x0C);
	}
}
