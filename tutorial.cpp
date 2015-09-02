#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "tutorial.h"
#include <windows.h>
#include "animation.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <MMSystem.h>

using namespace std;


extern Console console;
extern bool keyPressed[K_COUNTbv];
extern Console console;
extern double elapsedTime;
extern double deltaTime;
extern stage state;
PCSPRITE tutorialText;
char tutorialTextFile[]="tutorial.txt";
extern char tutorialPage[];
int page = 1;


//done by victor 
void page_change()
{
	//check what keys the player pressed 
	if(keyPressed[K_LEFT]&& page >1)
	{
		page--;
	}
	if(keyPressed[K_RIGHT]&& page<4)
	{
		page++;
	}
	if(keyPressed[K_BACKSPACE])
	{
		state = menu;
	}
	if(page <= 1)
	{
		page = 1;
	}
}

void init_tutorial(stage changeState)
{
	elapsedTime = 0.0;
	tutorialText=load_animation(tutorialTextFile);
	state=changeState;
}

//Done By victor
void renderTutorial()
{
	colour(0x0F);
	//check what page they are in
	if(page == 1)
	{
        render_animation(tutorialText,0,10,10,0x0F);
		console.writeToBuffer(10,24,"PRESS BACK SPACE TO MENU",0x0F);
	}
	if(page == 2)
	{
        render_animation(tutorialText,1,10,10,0x0F);
		console.writeToBuffer(10,24,"PRESS BACK SPACE TO MENU",0x0F);
	}
	if(page == 3)
	{
        render_animation(tutorialText,2,10,10,0x0F);
		console.writeToBuffer(10,24,"PRESS BACK SPACE TO MENU",0x0F);
	}
	if(page == 4)
	{
		render_animation(tutorialText,3,10,10,0x0F);
		console.writeToBuffer(10,24,"PRESS BACK SPACE TO MENU",0x0F);
	}
}