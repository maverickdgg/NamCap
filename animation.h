#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "game.h"

typedef struct cSprite
{
	int	col, row, nframe; 
	char*** frames; 

	cSprite(int nf, int nrow, int ncol)
	{
		row = nrow; 
		col = ncol;
		nframe = nf; 

		frames = new char**[nframe]; 
		for (int i=0;i<nframe;i++)
		{
			frames[i] = new char*[row]; 
			for (int j=0; j<row;j++)
				frames[i][j] = new char[col]; 
		}
	}

	~cSprite()
	{
		for (int i=0;i<nframe;i++)
		{
			for (int j=0; j<row;i++)
			{
				delete [] frames[i][j]; 
			}
			delete [] frames[i]; 
		}
		delete frames; 
	}
}
CSPRITE, * PCSPRITE;

PCSPRITE load_animation(char* fname);
void render_animation(PCSPRITE pAnimation, int frame, int x,int y, WORD color);
void free_animation(PCSPRITE);
void init_intro(stage changeState);
void init_menuAnime();
void renderIntro(stage changeState);
void renderMenuAnime();

#endif 