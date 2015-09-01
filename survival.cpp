#include "survival.h"
#include "Framework\console.h"
#include "GameUI.h"
#include"ai.h"
#include <iostream>

extern bool keyPressed[K_COUNTbv];
extern const int ciOffsetX;
extern const int ciOffsetY;
extern char map3[];
extern PMAP pacMap;
extern stage state;

extern COORD charLocation;
extern COORD charLocation2;

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
int g_idirection10;
int g_idirection11;
int g_idirection12;
int g_idirection13;
int g_idirection14;
int g_idirection15;
int g_idirection16;
int g_idirection17;
int g_idirection18;
int g_idirection19;
int g_idirection20;
//extern int g_idirection10;

extern int		g_iChangeMod;
extern int		g_iChangeCol;
extern double elapsedTime;
extern double deltaTime;
extern short sPacMap[21][38];
extern Console console;
extern void getInput();
bool survival = true;

SurvivalAI ghost1;
SurvivalAI ghost2;
SurvivalAI ghost3;
SurvivalAI ghost4;
SurvivalAI ghost5;
SurvivalAI ghost6;
SurvivalAI ghost7;
SurvivalAI ghost8;
SurvivalAI ghost9;
SurvivalAI ghost10;
SurvivalAI ghost11;
SurvivalAI ghost12;
SurvivalAI ghost13;
SurvivalAI ghost14;
SurvivalAI ghost15;
SurvivalAI ghost16;
SurvivalAI ghost17;
SurvivalAI ghost18;
SurvivalAI ghost19;
SurvivalAI ghost20;
SurvivalAI* arrghosts[20] = {&ghost1,&ghost2,&ghost3,&ghost4,&ghost5,&ghost6,&ghost7,&ghost8,&ghost9,&ghost10,&ghost11,&ghost12,&ghost13,&ghost14,&ghost15,&ghost16,&ghost17,&ghost18,&ghost19,&ghost20};

//Done By Amirul
void init_survival(stage changeState){
		elapsedTime = 0.0;
		pacMap=load_map(2);
		PlaySound(NULL,0,0);
		PlaySound(TEXT("Donkey Kong Theme song"),NULL,SND_LOOP | SND_ASYNC);

        charLocation.X = 38;
        charLocation.Y = 20;

        arrghosts[0] -> ghosts.X=39;
        arrghosts[0] -> ghosts.Y=13;

		arrghosts[1] -> ghosts.X=2+ciOffsetX;
        arrghosts[1] -> ghosts.Y=2+ciOffsetY;

		arrghosts[2] -> ghosts.X=36+ciOffsetX;
		arrghosts[2] -> ghosts.Y=19+ciOffsetY;

		arrghosts[3] -> ghosts.X=23+ciOffsetX;
		arrghosts[3] -> ghosts.Y=19+ciOffsetY;

		arrghosts[4] -> ghosts.X=15+ciOffsetX;
		arrghosts[4] -> ghosts.Y=19+ciOffsetY;

		arrghosts[5] -> ghosts.X=23+ciOffsetX;
		arrghosts[5] -> ghosts.Y=19+ciOffsetY;

		arrghosts[6] -> ghosts.X=2+ciOffsetX;
		arrghosts[6] -> ghosts.Y=19+ciOffsetY;

		arrghosts[7] -> ghosts.X=36+ciOffsetX;
        arrghosts[7] -> ghosts.Y=19+ciOffsetY;

		arrghosts[8] -> ghosts.X=14+ciOffsetX;
        arrghosts[8] -> ghosts.Y=19+ciOffsetY;

		arrghosts[9] -> ghosts.X=14+ciOffsetX;
        arrghosts[9] -> ghosts.Y=19+ciOffsetY;

		arrghosts[10] -> ghosts.X=14+ciOffsetX;
        arrghosts[10] -> ghosts.Y=19+ciOffsetY;

		arrghosts[11] -> ghosts.X=14+ciOffsetX;
        arrghosts[11] -> ghosts.Y=19+ciOffsetY;

		arrghosts[12] -> ghosts.X=14+ciOffsetX;
        arrghosts[12] -> ghosts.Y=19+ciOffsetY;

		arrghosts[12] -> ghosts.X=14+ciOffsetX;
        arrghosts[12] -> ghosts.Y=19+ciOffsetY;

		arrghosts[13] -> ghosts.X=14+ciOffsetX;
        arrghosts[13] -> ghosts.Y=19+ciOffsetY;

		arrghosts[14] -> ghosts.X=14+ciOffsetX;
        arrghosts[14] -> ghosts.Y=19+ciOffsetY;

		arrghosts[15] -> ghosts.X=14+ciOffsetX;
        arrghosts[15] -> ghosts.Y=19+ciOffsetY;

		arrghosts[16] -> ghosts.X=14+ciOffsetX;
        arrghosts[16] -> ghosts.Y=19+ciOffsetY;

		arrghosts[17] -> ghosts.X=14+ciOffsetX;
        arrghosts[17] -> ghosts.Y=19+ciOffsetY;

		arrghosts[18] -> ghosts.X=14+ciOffsetX;
        arrghosts[18] -> ghosts.Y=19+ciOffsetY;

		arrghosts[19] -> ghosts.X=14+ciOffsetX;
        arrghosts[19] -> ghosts.Y=19+ciOffsetY;

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
        state=changeState;	
}

//Done By Amirul
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
			monster(arrghosts[0]->ghosts,g_idirection);
		}
		if(elapsedTime>=10.0){
			monster(arrghosts[1]->ghosts,g_idirection2);
		}
		if(elapsedTime>=20.0){
			monster(arrghosts[2]->ghosts,g_idirection3);
		}
		if(elapsedTime>=30.0){
			monster(arrghosts[3]->ghosts,g_idirection4);
		}
		if(elapsedTime>=40.0){
			monster(arrghosts[4]->ghosts,g_idirection5);
		}
		if(elapsedTime>=50.0){
			monster(arrghosts[5]->ghosts,g_idirection6);
		}
		if(elapsedTime>=60.0){
			monster(arrghosts[6]->ghosts,g_idirection7);
		}
		if(elapsedTime>=70.0){
			monster(arrghosts[7]->ghosts,g_idirection8);
		}
		if(elapsedTime>=80.0){
			monster(arrghosts[8]->ghosts,g_idirection9);
		}
		if(elapsedTime>=90.0){
			monster(arrghosts[9]->ghosts,g_idirection9);
		}
		if(elapsedTime>=100.0){
			monster(arrghosts[10]->ghosts,g_idirection9);
		}
		if(elapsedTime>=110.0){
			monster(arrghosts[11]->ghosts,g_idirection9);
		}
		if(elapsedTime>=120.0){
			monster(arrghosts[12]->ghosts,g_idirection9);
		}
		if(elapsedTime>=130.0){
			monster(arrghosts[13]->ghosts,g_idirection9);
		}
		if(elapsedTime>=140.0){
			monster(arrghosts[14]->ghosts,g_idirection9);
		}
		if(elapsedTime>=150.0){
			monster(arrghosts[15]->ghosts,g_idirection9);
		}
		if(elapsedTime>=160.0){
			monster(arrghosts[16]->ghosts,g_idirection9);
		}
		if(elapsedTime>=170.0){
			monster(arrghosts[17]->ghosts,g_idirection9);
		}
		if(elapsedTime>=180.0){
			monster(arrghosts[18]->ghosts,g_idirection9);
		}
		if(elapsedTime>=190.0){
			monster(arrghosts[19]->ghosts,g_idirection9);
		}
		
}

//Done By Amirul
void renderMapSurvival()
{
    // Set up sample colours, and output shadings
    colour(0x0F);
    insertmap(pacMap);
	
}


//Done By Amirul
void renderCharacterSurvival()
{
    // Draw the location of the character
    console.writeToBuffer(charLocation, (char)g_iChangeMod, 0x0C+g_iChangeCol);
		
	if(elapsedTime>=1.0){
			console.writeToBuffer(arrghosts[0]->ghosts,232,0x0F);
			eneXp1(arrghosts[0]->ghosts,charLocation);
		}
	if(elapsedTime>=11.0){
			console.writeToBuffer(arrghosts[1]->ghosts,232,0x0F);
			eneXp1(arrghosts[1]->ghosts,charLocation);
		}
	if(elapsedTime>=21.0){
			console.writeToBuffer(arrghosts[2]->ghosts,232,0x0F);
			eneXp1(arrghosts[2]->ghosts,charLocation);
		}
	if(elapsedTime>=31.0){
			console.writeToBuffer(arrghosts[3]->ghosts,232,0x0F);
			eneXp1(arrghosts[3]->ghosts,charLocation);
		}
	if(elapsedTime>=41.0){
			console.writeToBuffer(arrghosts[4]->ghosts,232,0x0F);
			eneXp1(arrghosts[4]->ghosts,charLocation);
		}
	if(elapsedTime>=51.0){
			console.writeToBuffer(arrghosts[5]->ghosts,232,0x0F);
			eneXp1(arrghosts[5]->ghosts,charLocation);
		}
	if(elapsedTime>=61.0){
			console.writeToBuffer(arrghosts[6]->ghosts,232,0x0F);
			eneXp1(arrghosts[6]->ghosts,charLocation);
		}
	if(elapsedTime>=71.0){
			console.writeToBuffer(arrghosts[7]->ghosts,232,0x0F);
			eneXp1(arrghosts[7]->ghosts,charLocation);
		}
	if(elapsedTime>=81.0){
			console.writeToBuffer(arrghosts[8]->ghosts,232,0x0F);
			eneXp1(arrghosts[8]->ghosts,charLocation);
		}
	if(elapsedTime>=91.0){
			console.writeToBuffer(arrghosts[9]->ghosts,232,0x0F);
			eneXp1(arrghosts[9]->ghosts,charLocation);
		}
	if(elapsedTime>=101.0){
			console.writeToBuffer(arrghosts[10]->ghosts,232,0x0F);
			eneXp1(arrghosts[10]->ghosts,charLocation);
		}
	if(elapsedTime>=111.0){
			console.writeToBuffer(arrghosts[11]->ghosts,232,0x0F);
			eneXp1(arrghosts[11]->ghosts,charLocation);
		}
	if(elapsedTime>=121.0){
			console.writeToBuffer(arrghosts[12]->ghosts,232,0x0F);
			eneXp1(arrghosts[12]->ghosts,charLocation);
		}
	if(elapsedTime>=131.0){
			console.writeToBuffer(arrghosts[13]->ghosts,232,0x0F);
			eneXp1(arrghosts[13]->ghosts,charLocation);
		}
	if(elapsedTime>=141.0){
			console.writeToBuffer(arrghosts[14]->ghosts,232,0x0F);
			eneXp1(arrghosts[14]->ghosts,charLocation);
		}
	if(elapsedTime>=151.0){
			console.writeToBuffer(arrghosts[15]->ghosts,232,0x0F);
			eneXp1(arrghosts[15]->ghosts,charLocation);
		}
	if(elapsedTime>=161.0){
			console.writeToBuffer(arrghosts[16]->ghosts,232,0x0F);
			eneXp1(arrghosts[16]->ghosts,charLocation);
		}
	if(elapsedTime>=171.0){
			console.writeToBuffer(arrghosts[17]->ghosts,232,0x0F);
			eneXp1(arrghosts[17]->ghosts,charLocation);
		}
	if(elapsedTime>=181.0){
			console.writeToBuffer(arrghosts[18]->ghosts,232,0x0F);
			eneXp1(arrghosts[18]->ghosts,charLocation);
		}
	if(elapsedTime>=191.0){
			console.writeToBuffer(arrghosts[19]->ghosts,232,0x0F);
			eneXp1(arrghosts[19]->ghosts,charLocation);
		}

    if(g_iChangeMod > 6)
	{
		g_iChangeMod = 1;
	}
	if(g_iChangeCol > 6)
	{
		g_iChangeCol = 1;
	}
	//eneXp1(charLocation2,charLocation);
    teleport(charLocation,tp1,tp2);
}

//Done By Amirul
void render_end2()
{
		pacMap=load_map(6);
		insertmap(pacMap);
		console.writeToBuffer(30,27,"GAME OVER NOOB!!!!!!",0x0C);
		console.writeToBuffer(25,28,"HAHAHAHAHAHAHAHAHA!!!!!!!!!!",0x0C);
		console.writeToBuffer(17,29,"You Died, Press Enter To Play Another Mode!!!!!!",0x0C);
		console.writeToBuffer(22,30,"PRESS ESCAPE TO RAGEQUIT, MUAHAHAHAHA",0x0C);
}