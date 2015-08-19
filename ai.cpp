#include"ai.h"
#include "game.h"

extern short sPacMap[21][38];
extern Console console;
const int ciOffsetX=20;
const int ciOffsetY=5;

int reroll(int& x){
    x=rand()%4;
    return x;
}

void monster(COORD& monster1,int& g_idirection){
    bool bcollision =false;
    if(bcollision==false){
            if(g_idirection==0)
            {
                if(wall_left(monster1) == true){
                    bcollision=true;
                }
                else{ 
                monster1.X--;
                }
            }
            if(g_idirection==1)
            {
                if(wall_right(monster1)==true){
                    bcollision=true;
                }
                else{
                monster1.X++;
                }
            }
            if(g_idirection==2)
            {
               if(wall_down(monster1)==true){
                    bcollision=true;
                }
                else{
                monster1.Y++;
                }
            }
            if(g_idirection==3)
            {
                if(wall_up(monster1)==true){
                    bcollision=true;
                }
                else{
                monster1.Y--;
                }
            }
            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false){
                bcollision=true;
            }
            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_left(monster1)==false ){
                bcollision=true;
            }
            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_right(monster1)==false){
                bcollision=true;
            }
            if(wall_up(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false){
                bcollision=true;
            }
            if(wall_down(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false){
                bcollision=true;
            }
    }
    if(bcollision==true){
        reroll(g_idirection);
    }
}



bool wall_left(COORD location){
    if(sPacMap[location.Y-ciOffsetY][location.X-1-ciOffsetX] == 1){
        return true;
    }
    else{
        return false;
    }
}

bool wall_right(COORD location){
    if(sPacMap[location.Y-ciOffsetY][location.X+1-ciOffsetX] == 1){
        return true;
    }
    else{
        return false;
    }
}

bool wall_up(COORD location){
    if(sPacMap[location.Y-1-ciOffsetY][location.X-ciOffsetX] == 1){
        return true;
    }
    else{
        return false;
    }
}

bool wall_down(COORD location){
    if(sPacMap[location.Y+1-ciOffsetY][location.X-ciOffsetX] == 1){
        return true;
    }
    else{
        return false;
    }
}
