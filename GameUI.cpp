#include "gameUI.h"
#include "Framework/console.h"

const short g_csRows=21;
const short g_csCol=38;
const unsigned char wall=178;
void insertmap(short sMap[g_csRows][g_csCol])
{
    const int csOffsetX=20;
    const int csOffsetY=5;
    for(int i=csOffsetX;i<g_csCol+csOffsetX;++i){
        for(int j=csOffsetY;j<g_csRows+csOffsetY;++j){
            gotoXY(i,j);
            if(sMap[j-csOffsetY][i-csOffsetX]==1){
                cout<<wall;
            }
        }
    }
}


void printscore()
{
	const WORD colors[] =   
	{
		0x1B,0x46                        
	};
	gotoXY(0,2);
	colour(colors[0]);
	cout<<"Player 1";
	gotoXY(0,3);
	colour(colors[0]);
	cout<<"Score: ";
	gotoXY(70, 2);
	colour(colors[1]);
	cout<<"Player 2";
	gotoXY(70, 3);
	colour(colors[1]);
	cout<<"Score: ";
	gotoXY(0,5);
	//Blocks Map;
	//numbers(Map, map , 178);
}