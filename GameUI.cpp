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

void insertmap(PMAP sMap)
{
	console.writeToBuffer(0,2,"Player1",0x1B);
	console.writeToBuffer(0,3,"Score: ",0x1B);
	console.writeToBuffer(8,3,score,0x1B);
	console.writeToBuffer(68,2,"Player2",0x46);
	console.writeToBuffer(68,3,"Score: ",0x46);
    console.writeToBuffer(76,3,score2,0x46);

    for(int j=ciOffsetY;j<sMap->nrow+ciOffsetY;++j){
        for(int i=ciOffsetX;i<sMap->ncol+ciOffsetX;++i){ 
            if(sMap->data[j-ciOffsetY][i-ciOffsetX]=='1'){
                console.writeToBuffer(i,j,wall,0x0F);
            }
            if(sMap->data[j-ciOffsetY][i-ciOffsetX]=='0'){
                console.writeToBuffer(i,j,coin,0x06);
            }
			if(sMap->data[j-ciOffsetY][i-ciOffsetX]==' '){
                console.writeToBuffer(i,j,static_cast<unsigned char>(' '),0x0F);
            }
        }  
    }
}

void printText(PMAP text){
	for(int j=ciOffsetY;j<text->nrow+ciOffsetY;++j){
        for(int i=ciOffsetX;i<text->ncol+ciOffsetX;++i){
			console.writeToBuffer(i,j,static_cast<unsigned char>(text->data[i-ciOffsetX][j-ciOffsetY]),0x0F);
		}
	}
}