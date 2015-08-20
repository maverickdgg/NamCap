#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "map.h"

const short g_csRows=21;
const short g_csCol=38;
const int csOffsetX=20;
const int csOffsetY=5;
const unsigned char wall=178;
unsigned char coin=48;
extern Console console;
extern int score;
extern int score2;


short readfile(short sMapInUse[][38],string txt)
{
	ifstream inData;
	string data;
	inData.open (txt); // associate & open files
	while (!inData.eof()) 
	{
		for(short i=0;i<g_csRows;++i)
		{
			getline(inData,data); // read from input file
			for(short j=0;j<g_csCol;++j)
			{
				sMapInUse[i][j]=static_cast<short>(data[j]-'0');
			}
			//data="";
		}
	}
	return sMapInUse[21][38];
	inData.close (); // close files
}

void insertmap(short sMap[21][38])
{

	console.writeToBuffer(0,2,"Player1",0x1B);
	console.writeToBuffer(0,3,"Score: ",0x1B);
	console.writeToBuffer(8,3,score,0x1B);
	console.writeToBuffer(68,2,"Player2",0x46);
	console.writeToBuffer(68,3,"Score: ",0x46);
    console.writeToBuffer(76,3,score2,0x46);

    for(int i=csOffsetX;i<g_csCol+csOffsetX;++i){
        for(int j=csOffsetY;j<g_csRows+csOffsetY;++j){ 
            if(sMap[j-csOffsetY][i-csOffsetX]==1){
                console.writeToBuffer(i,j,wall,0x0F);
            }
			if(sMap[j-csOffsetY][i-csOffsetX]==0){
                console.writeToBuffer(i,j,coin,0x0E);
            }
        }  
    }
}
