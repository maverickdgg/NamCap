#include"ai.h"
#include "game.h"

extern short sPacMap[21][38];
extern Console console;
    const int ciOffsetX=20;
    const int ciOffsetY=5;

  

void monster(COORD monster1, int idirection){
    bool bcollision =false;
    switch(idirection){
        case 0:
            if(sPacMap[monster1.Y-ciOffsetY][monster1.X-1-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{ 
                monster1.X--;
                }
        case 1:
            if(sPacMap[monster1.Y-ciOffsetY][monster1.X+1-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.X++;
                }
        case 2:
            if(sPacMap[monster1.Y+1-ciOffsetY][monster1.X-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.Y++;
                }
        case 3:
            if(sPacMap[monster1.Y-1-ciOffsetY][monster1.X-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.Y--;
                }

    }
    /*if(bcollision==false){
            if(cdirection==0)
            {
                if(sPacMap[monster1.Y-ciOffsetY][monster1.X-1-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{ 
                monster1.X--;
                }
            }
            if(cdirection==1)
            {
                if(sPacMap[monster1.Y-ciOffsetY][monster1.X+1-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.X++;
                }
            }
            if(cdirection==2)
            {
               if(sPacMap[monster1.Y+1-ciOffsetY][monster1.X-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.Y++;
                }
            }
            if(cdirection==3)
            {
                if(sPacMap[monster1.Y-1-ciOffsetY][monster1.X-ciOffsetX] == 1){
                    bcollision=true;
                }
                else{
                monster1.Y--;
                }
            }       
    }*/
}