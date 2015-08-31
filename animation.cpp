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

char intro_animation[]="intro_animation.txt";

//Done By Daniel(Leader)
PCSPRITE load_animation(char* fname)
{
	PCSPRITE animation = NULL; 
	ifstream infile; 
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
		animation = new CSPRITE(nframe,nrow,ncol); 
		for (i=0;i<nframe;i++)
		{
			j =0; 
			while (j<nrow)
			{
				string line; 
				getline(infile,line); 
				if (strlen(line.c_str())>0)
				{
					memcpy(animation->frames[i][j],line.c_str(), ncol);
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
	for (int i=0;i<animation->row;i++) 
	{
        for(int j=0;j<animation->col;++j)
		console.writeToBuffer(x+j,y+i,static_cast<unsigned char>(animation->frames[frame][i][j]),color); 
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

//Done By Daniel(Leader)
void renderIntro(stage changeState)
{
	colour(0x0F);
	if(elapsedTime <= 1)
	{
		//printText(introMap);
        render_animation(introAnimation,0,25,17,0x0F);
	}
	if(elapsedTime <=2 && elapsedTime >1)
	{
		//printText(introMap2);
        render_animation(introAnimation,1,25,17,0x0F);

	}
	if(elapsedTime <=3 && elapsedTime >2)
	{
		//printText(introMap3);
        render_animation(introAnimation,2,25,17,0x0F);
        console.writeToBuffer(25,28,"  PD Entertainment",0x0F);
	}
	if(elapsedTime >= 3)
	{
		state=changeState;
	}
}