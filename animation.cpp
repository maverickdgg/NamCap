#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <MMSystem.h>

using namespace std;

#include "Framework\console.h"
#include "animation.h"

extern Console console;
extern bool keyPressed[K_COUNTbv];
extern Console console;
extern double elapsedTime;
extern double deltaTime;
extern stage state;
PCSPRITE introAnimation;
extern PCSPRITE menuAnimation;

char intro_animation[]="intro_animation.txt";
extern char menu_animation[];

//Done By Daniel(Leader)
PCSPRITE load_animation(char* fname)
{
	PCSPRITE animation = NULL; 
	ifstream infile; 
	//check the row,column and frame 
	int nrow, ncol, nframe, i,j; 

	infile.open(fname); 	
	if (!infile)
	{
        console.writeToBuffer(0,0,"Error Opening file",0x0F);
		exit(1); 
	}
	if (infile.good())
	{
        //getting frames and size of animation
		infile >> nframe >> nrow >> ncol ; 		
		// allocate memory for animation data
		animation = new CSPRITE(nframe ,nrow ,ncol); 
		for ( i = 0; i < nframe;i++)
		{
			j = 0; 
			while (j < nrow)
			{
				string line; 
				getline(infile,line); 
				if (strlen(line.c_str()) > 0)
				{
					memcpy(animation -> frames[i][j],line.c_str(), ncol);
                    //null terminator for each row
					animation->frames[i][j][ncol] = 0;
					j++; 
				}
			}
		}
	}
	return animation; 
}

//Done By Daniel(Leader)
//function to delete animation
void free_animation(PCSPRITE animation)
{
	delete animation; 
}

//Done By Daniel(Leader)
//rendering one frame of animation
void render_animation(PCSPRITE animation, int frame, int x,int y, WORD color)
{
	for (int i=0;i < animation -> row;i++) 
	{
        for(int j = 0;j < animation -> col;++j)
		console.writeToBuffer(x + j,y + i,static_cast<unsigned char>(animation->frames[frame][i][j]),color); 
	}
}

//Done By Daniel(Leader)
void init_intro(stage changeState)
{
	elapsedTime = 0.0;

    PlaySound(NULL,0,0);
	PlaySound(TEXT("Nvidia Intro.wav"),NULL,SND_ASYNC);
    introAnimation=load_animation(intro_animation);

    state=changeState;
}

//Done By victor
void renderIntro(stage changeState)
{
	colour(0x0F);
	if(elapsedTime <= 1)
	{
		//printText(introMap);
        render_animation(introAnimation,0,20,10,0x0F);
	}
	if(elapsedTime <= 2 && elapsedTime > 1)
	{
		//printText(introMap2);
        render_animation(introAnimation,1,20,10,0x0F);

	}
	if(elapsedTime <= 4 && elapsedTime > 2)
	{
		//printText(introMap3);
        render_animation(introAnimation,2,20,10,0x0F);
        console.writeToBuffer(21,21," PD Entertainment",0x0F);
	}
	if(elapsedTime >= 4)
	{
		state=changeState;
	}
}
//done by victor
void renderMenuAnime()
{
	colour(0x0F);
	//time the animation and render it 
	if(elapsedTime >= 0)
	{
        render_animation(menuAnimation,0,20,10,0x0F);
	}
	if(elapsedTime >= 0.1)
	{
        render_animation(menuAnimation,1,20,10,0x0F);

	}
	if(elapsedTime >= 0.2)
	{
        render_animation(menuAnimation,2,20,10,0x0F);
	}
	if(elapsedTime >= 0.3)
	{
        render_animation(menuAnimation,3,20,10,0x0F);
	}
	if(elapsedTime >= 0.4)
	{
        render_animation(menuAnimation,4,20,10,0x0F);
	}
	if(elapsedTime >= 0.5)
	{
        render_animation(menuAnimation,5,20,10,0x0F);
	}
	if(elapsedTime >= 0.6)
	{
        render_animation(menuAnimation,6,20,10,0x0F);
	}
	if(elapsedTime >= 0.7)
	{
        render_animation(menuAnimation,7,20,10,0x0F);
	}
	if(elapsedTime >= 0.8)
	{
        render_animation(menuAnimation,8,20,10,0x0F);
	}
	if(elapsedTime >= 0.9)
	{
        render_animation(menuAnimation,9,20,10,0x0F);
	}
	if(elapsedTime >= 1.0)
	{
        render_animation(menuAnimation,10,20,10,0x0F);
	}
	if(elapsedTime >= 1.1)
	{
        render_animation(menuAnimation,11,20,10,0x0F);
	}
	if(elapsedTime >= 1.2)
	{
        render_animation(menuAnimation,12,20,10,0x0F);
	}
	if(elapsedTime >= 1.3)
	{
        render_animation(menuAnimation,13,20,10,0x0F);
	}
	if(elapsedTime >= 1.4)
	{
        render_animation(menuAnimation,14,20,10,0x0F);
	}
	if(elapsedTime >= 1.5)
	{
        render_animation(menuAnimation,15,20,10,0x0F);
	}
	if(elapsedTime >= 1.6)
	{
        render_animation(menuAnimation,16,20,10,0x0F);
	}
	if(elapsedTime >= 1.7)
	{
        render_animation(menuAnimation,17,20,10,0x0F);
	}
	if(elapsedTime >= 1.8)
	{
        render_animation(menuAnimation,18,20,10,0x0F);
	}
	if(elapsedTime >= 1.9)
	{
        render_animation(menuAnimation,19,20,10,0x0F);
	}
	if(elapsedTime >= 2.0)
	{
        render_animation(menuAnimation,20,20,10,0x0F);
	}
	if(elapsedTime >= 2.1)
	{
        render_animation(menuAnimation,21,20,10,0x0F);
	}
	if(elapsedTime >= 2.2)
	{
        render_animation(menuAnimation,22,20,10,0x0F);
	}
	if(elapsedTime >= 2.3)
	{
        render_animation(menuAnimation,23,20,10,0x0F);
	}
	if(elapsedTime >= 2.4)
	{
        render_animation(menuAnimation,24,20,10,0x0F);
	}
	if(elapsedTime >= 2.5)
	{
        render_animation(menuAnimation,25,20,10,0x0F);
	}
	if(elapsedTime >= 2.6)
	{
        render_animation(menuAnimation,26,20,10,0x0F);
	}
	if(elapsedTime >= 2.7)
	{
        render_animation(menuAnimation,27,20,10,0x0F);
	}
	if(elapsedTime >= 2.8)
	{
        render_animation(menuAnimation,28,20,10,0x0F);
	}
	if(elapsedTime >= 2.9)
	{
        render_animation(menuAnimation,29,20,10,0x0F);
	}
	if(elapsedTime >= 3.0)
	{
        render_animation(menuAnimation,30,20,10,0x0F);
	}
	if(elapsedTime >= 3.1)
	{
        render_animation(menuAnimation,31,20,10,0x0F);
	}
	if(elapsedTime >= 3.2)
	{
        render_animation(menuAnimation,32,20,10,0x0F);
	}
	if(elapsedTime >= 3.3)
	{
        render_animation(menuAnimation,33,20,10,0x0F);
	}
	if(elapsedTime >= 3.4)
	{
        render_animation(menuAnimation,34,20,10,0x0F);
	}
	if(elapsedTime >= 3.5)
	{
        render_animation(menuAnimation,35,20,10,0x0F);
	}
	if(elapsedTime >= 3.6)
	{
        render_animation(menuAnimation,36,20,10,0x0F);
	}
	
}