#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"
#include "map.h"

const short g_csRows=21;
const short g_csCol=38;
const short g_csCol2=15;
extern const int ciOffsetX=20;
extern const int ciOffsetY=5;
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

short readExactFile(short sMapInUse[][15],string txt)
{
	ifstream inData;
	string data;
	inData.open (txt); // associate & open files
	while (!inData.eof()) 
	{
		for(short i=0;i<g_csRows;++i)
		{
			getline(inData,data); // read from input file
			for(short j=0;j<g_csCol2;++j)
			{
				sMapInUse[i][j]=static_cast<short>(data[j]-'0');
			}
			//data="";
		}
	}
	return sMapInUse[21][15];
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

    for(int i=ciOffsetX;i<g_csCol+ciOffsetX;++i){
        for(int j=ciOffsetY;j<g_csRows+ciOffsetY;++j){ 
            if(sMap[j-ciOffsetY][i-ciOffsetX]==1){
                console.writeToBuffer(i,j,wall,0x0F);
            }
			if(sMap[j-ciOffsetY][i-ciOffsetX]==0){
                console.writeToBuffer(i,j,coin,0x06);
            }
        }  
    }
}

void printExactFile(short sMap[21][15])
{
	for(int i=ciOffsetX;i<g_csCol2+ciOffsetX;++i){
        for(int j=ciOffsetY;j<g_csRows+ciOffsetY;++j){ 
            if(sMap[j-ciOffsetY][i-ciOffsetX]==1){
                console.writeToBuffer(i,j,wall,0x0F);
            }
			if(sMap[j-ciOffsetY][i-ciOffsetX]==0){
                console.writeToBuffer(i,j,' ',0x0E);
            }
        }  
    }
}