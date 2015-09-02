#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "map.h"

const short g_csRows = 21;
const short g_csCol = 38;
const short g_csCol2 = 15;
extern const int ciOffsetX = 20;
extern const int ciOffsetY = 5;
const unsigned char wall = 178;
unsigned char coin = 48;
extern Console console;
extern int score;
extern int score2;

//Done By Amirul
//With tips from Mr Alex Toh
void insertmap(PMAP sMap)
{
	//use the row and column in the text file to generate the map
	for(int j = ciOffsetY;j < sMap-> nrow + ciOffsetY;++j)
	{
        for(int i = ciOffsetX;i < sMap-> ncol + ciOffsetX;++i)
		{ 
            if(sMap -> data[j - ciOffsetY][i - ciOffsetX] == '1')
			{
                console.writeToBuffer(i,j,wall,0x0F);
            }
            if(sMap -> data[j - ciOffsetY][i - ciOffsetX] == '0')
			{
                console.writeToBuffer(i,j,coin,0x06);
            }
			if(sMap -> data[j - ciOffsetY][i - ciOffsetX] == ' ')
			{
                console.writeToBuffer(i,j,static_cast<unsigned char>(' '),0x0F);
            }
        }  
    }
}