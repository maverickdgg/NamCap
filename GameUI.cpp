#include "gameUI.h"
#include "Framework/console.h"
#include "game.h"

const short g_csRows=21;
const short g_csCol=38;
const int csOffsetX=20;
const int csOffsetY=5;
const unsigned char wall=178;
extern Console console;

short readfile(short sMapInUse[][38])
{
	ifstream inData;
	string data;
	inData.open ("map.txt"); // associate & open files
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

void insertmap(short sMap[g_csRows][g_csCol])
{
	console.writeToBuffer(0,2,"Player1",0x1B);
	console.writeToBuffer(0,3,"Score: ",0x1B);
	console.writeToBuffer(70,2,"Player2",0x46);
	console.writeToBuffer(70,3,"Score: ",0x46);

    for(int i=csOffsetX;i<g_csCol+csOffsetX;++i){
        for(int j=csOffsetY;j<g_csRows+csOffsetY;++j){ 
            if(sMap[j-csOffsetY][i-csOffsetX]==1){
                console.writeToBuffer(i,j,wall,0x0F);
            }
        }  
    }
}

/*void insertmap1(short* sMap[21])
{
	console.writeToBuffer(0,2,"Player1",0x1B);
	console.writeToBuffer(0,3,"Score: ",0x1B);
	console.writeToBuffer(70,2,"Player2",0x46);
	console.writeToBuffer(70,3,"Score: ",0x46);

    for(int i=csOffsetX;i<g_csCol+csOffsetX;++i){
        for(int j=csOffsetY;j<g_csRows+csOffsetY;++j){ 
            if(sMap[j-csOffsetY][i-csOffsetX]==1){
                console.writeToBuffer(i,j,wall,0x0F);
            }
        }  
    }
}*/


/*void printscore()
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
}*/