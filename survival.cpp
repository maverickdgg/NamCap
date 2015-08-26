#include "survival.h"
#include "game.h"
#include "Framework\console.h"
#include "GameUI.h"
#include"ai.h"
#include <iostream>

extern bool keyPressed[K_COUNTbv];
extern const int ciOffsetX;
extern const int ciOffsetY;
extern char map3[];

extern COORD charLocation;
extern COORD charLocation2;
extern COORD ghost1;
extern COORD ghost2;
extern COORD ghost3;
extern COORD ghost4;
extern COORD ghost5;
extern COORD ghost6;
extern COORD ghost7;
extern COORD ghost8;
extern COORD ghost9;
//extern COORD ghost10;

extern COORD tp1;
extern COORD tp2;
extern int g_idirection;
extern int g_idirection2;
extern int g_idirection3;
extern int g_idirection4;
extern int g_idirection5;
extern int g_idirection6;
extern int g_idirection7;
extern int g_idirection8;
extern int g_idirection9;
//extern int g_idirection10;

extern int		g_iChangeMod;
extern int		g_iChangeCol;
extern double elapsedTime;
extern double deltaTime;
extern short sPacMap[21][38];
extern Console console;
extern void getInput();
bool survival = true;


void init_survival(){
    elapsedTime = 0.0;
		readfile(sPacMap,map3);

        charLocation.X = 38;
        charLocation.Y = 20;

        ghost1.X=39;
        ghost1.Y=13;

        ghost2.X=2+ciOffsetX;
        ghost2.Y=2+ciOffsetY;

        ghost3.X=36+ciOffsetX;
        ghost3.Y=19+ciOffsetY;

		ghost4.X=23+ciOffsetX;
        ghost4.Y=19+ciOffsetY;

		ghost5.X=15+ciOffsetX;
        ghost5.Y=19+ciOffsetY;

		ghost6.X=23+ciOffsetX;
        ghost6.Y=19+ciOffsetY;

		ghost7.X=2+ciOffsetX;
        ghost7.Y=19+ciOffsetY;

		ghost8.X=5+ciOffsetX;
        ghost8.Y=23+ciOffsetY;

		ghost9.X=14+ciOffsetX;
        ghost9.Y=11+ciOffsetY;

		/*ghost10.X=6+ciOffsetX;
        ghost10.Y=14+ciOffsetY;*/

        srand(time(NULL));
        g_idirection=rand()%4;
        g_idirection2=rand()%4;
        g_idirection3=rand()%4;
		g_idirection4=rand()%4;
		g_idirection5=rand()%4;
		g_idirection6=rand()%4;
        g_idirection7=rand()%4;
        g_idirection8=rand()%4;
		g_idirection9=rand()%4;
		/*g_idirection10=rand()%4;*/
}

void moveCharacter_survival()
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
		if(elapsedTime>=0.0){
			monster(ghost1,g_idirection);
		}
		if(elapsedTime>=10.0){
			monster(ghost2,g_idirection2);
		}
		if(elapsedTime>=20.0){
			monster(ghost3,g_idirection3);
		}
		if(elapsedTime>=30.0){
			monster(ghost4,g_idirection4);
		}
		if(elapsedTime>=40.0){
			monster(ghost5,g_idirection5);
		}
		if(elapsedTime>=50.0){
			monster(ghost6,g_idirection5);
		}
		if(elapsedTime>=60.0){
			monster(ghost7,g_idirection5);
		}
		if(elapsedTime>=70.0){
			monster(ghost8,g_idirection5);
		}
		if(elapsedTime>=80.0){
			monster(ghost9,g_idirection5);
		}
		/*if(elapsedTime>=90.0){
			monster(ghost10,g_idirection5);
		}*/
}

void renderMapSurvival()
{
    // Set up sample colours, and output shadings
    colour(0x0F);
    insertmap(sPacMap);
}

void renderCharacterSurvival()
{
    // Draw the location of the character
    console.writeToBuffer(charLocation, (char)g_iChangeMod, 0x0C+g_iChangeCol);
	if(elapsedTime>=0.0){
		console.writeToBuffer(ghost1,232,0x0B);
		eneXp1(ghost1,charLocation);
	}
	if(elapsedTime>=10.0){
		console.writeToBuffer(ghost2,232,0x0B);
		eneXp1(ghost2,charLocation);
	}
	if(elapsedTime>=20.0){
		console.writeToBuffer(ghost3,232,0x0B);
		eneXp1(ghost3,charLocation);
	}
	if(elapsedTime>=30.0){
		console.writeToBuffer(ghost4,232,0x0B);
		eneXp1(ghost4,charLocation);
	}
	if(elapsedTime>=40.0){
		console.writeToBuffer(ghost5,232,0x0B);
		eneXp1(ghost5,charLocation);
	}
	if(elapsedTime>=50.0){
		console.writeToBuffer(ghost6,232,0x0B);
		eneXp1(ghost6,charLocation);
	}
	if(elapsedTime>=60.0){
		console.writeToBuffer(ghost7,232,0x0B);
		eneXp1(ghost7,charLocation);
	}
	if(elapsedTime>=70.0){
		console.writeToBuffer(ghost8,232,0x0B);
		eneXp1(ghost8,charLocation);
	}
	if(elapsedTime>=80.0){
		console.writeToBuffer(ghost9,232,0x0B);
		eneXp1(ghost9,charLocation);
	}
	/*if(elapsedTime>=90.0){
		console.writeToBuffer(ghost10,232,0x0B);
		eneXp1(ghost10,charLocation);
	}*/

    if(g_iChangeMod > 6)
	{
		g_iChangeMod = 1;
	}
	if(g_iChangeCol > 6)
	{
		g_iChangeCol = 1;
	}
	eneXp1(charLocation2,charLocation);
    teleport(charLocation,tp1,tp2);
}

void render_end2()
{
	 console.writeToBuffer(35,15,"You Lose",0x0F);
}