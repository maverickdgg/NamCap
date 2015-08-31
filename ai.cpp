#include"ai.h"
#include "game.h"

extern short sPacMap[21][38];
extern Console console;
const int ciOffsetX=20;
const int ciOffsetY=5;
extern PMAP pacMap;

int reroll(int& x){
    x=rand()%4;
    return x;
}

//int stalker(int& direction,COORD ghost,COORD player){
//    int i=0;
//    int j=0;
//    if(ghost.X>player.X)
//    {
//        i = 0;
//    }
//    if(ghost.X<player.X){
//        i = 1;
//    }
//    if(ghost.Y<player.Y){
//        j = 2;
//    }
//    if(ghost.Y>player.Y){
//        j = 3;
//    }
//    int k=rand()%2;
//    if(ghost.X==player.X){
//        direction = j;
//    }
//    else if(ghost.Y==player.Y){
//        direction = i;
//    }
//    else if(k==0){
//        direction = i;
//    }
//    else if(k==1){
//        direction = j;
//    }
//    return direction;
//}
//
//
//0=L 1=R, 2=D , 3=U
//int stalker(int& direction,COORD ghost,COORD player){
//    int k=rand()%2;
//    int j=rand()%3;
//    // ghost at bottom right of player
//    if(ghost.X>player.X && ghost.Y>player.Y){
//        if(wall_up(ghost)==false){
//            direction=3;
//        }
//        else if(wall_left(ghost)==false){
//            direction=0;
//        }
//        else if(wall_left(ghost)==true && wall_up(ghost)==true){
//            if(k==0){
//                direction=1;
//            }
//            else{
//                direction=2;
//            }
//        }
//    }
//
//    // ghost at bottom left of player
//    if (ghost.X<player.X && ghost.Y>player.Y){
//        if(wall_right(ghost)==false){
//                direction=1;
//        }
//        else if(wall_up(ghost)==false){
//            direction=3;
//        }
//        
//        else if(wall_right(ghost)==true && wall_up(ghost)==true){
//            if(k==0){
//                direction=2;
//            }
//            else{
//                direction=0;
//            }
//        }
//    }
//
//    // ghost at top left of player
//    if(ghost.X<player.X && ghost.Y<player.Y){
//        if(wall_down(ghost)==false){
//            direction=2;
//        }
//        else if(wall_right(ghost)==false){
//            direction=1;
//        }
//        else if(wall_right(ghost)==true && wall_down(ghost)==true){
//            if (k==0){
//                direction=0;
//            }
//            else{
//                direction=3;
//            }
//        }
//    }
//
//    // ghost at top right of p[layer
//    if(ghost.X>player.X && ghost.Y<player.Y){
//        if(wall_left(ghost)==false){
//            direction=0;
//        }
//        else if(wall_down(ghost)==false){
//            direction=2;
//        }
//        else if (wall_down(ghost)==true && wall_left(ghost)==true){
//            if(k==0){
//                direction=3;
//            }
//            else {
//                direction=1;
//            }
//        }
//    }
//    
//    //ghost at left of player
//    if(ghost.X<player.X && ghost.Y==player.Y){
//        if(wall_right(ghost)==false){
//            direction=1;
//        }
//        else if(wall_right(ghost)==true){
//            if(j==0){
//                direction=3;
//            }
//            else if(j==1){
//                direction=2;
//            }
//            else {
//                direction=0;
//            }
//        }
//    }
//
//    //ghost at right of player
//
//    if(ghost.X>player.X && ghost.Y==player.Y){
//        if(wall_left(ghost)==false){
//            direction=0;
//        }
//        else if(wall_right(ghost)==true){
//            if(j==0){
//                direction=2;
//            }
//            else if(j==1){
//                direction=3;
//            }
//            else {
//                direction=1;
//            }
//        }
//    }
//
//   // ghost at top of player
//
//    if(ghost.X==player.X && ghost.Y<player.Y){
//        if(wall_down(ghost)==false){
//            direction=2;
//        }
//        else if(wall_right(ghost)==true){
//            if(j==0){
//                direction=0;
//            }
//            else if(j==1){
//                direction=1;
//            }
//            else {
//                direction=3;
//            }
//        }
//    }
//
//    //ghost below player
//    if(ghost.X==player.X && ghost.Y>player.Y){
//        if(wall_up(ghost)==false){
//            direction=3;
//        }
//        else if(wall_right(ghost)==true){
//            if(j==0){
//                direction=1;
//            }
//            else if(j==1){
//                direction=0;
//            }
//            else {
//                direction=2;
//            }
//        }
//    }
//    return direction;
//}
//void stalker_ghost(int& g_idirection,COORD& monster1,COORD player){
//    bool stalking=false;
//    if(stalking==false){
//            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false && stalking==false){
//                stalking=true;
//            }
//            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_left(monster1)==false && stalking==false){
//                stalking=true;
//            }
//            if(wall_up(monster1)==false && wall_down(monster1)==false && wall_right(monster1)==false&& stalking==false){
//                stalking=true;
//            }
//            if(wall_up(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false&& stalking==false){
//                stalking=true;
//            }
//            if(wall_down(monster1)==false && wall_left(monster1)==false && wall_right(monster1)==false&& stalking==false){
//                stalking=true;
//            }
//            if(g_idirection==0)
//            {
//                if(wall_left(monster1) == true){
//                    stalking=true;
//                }
//                else{
//                monster1.X--;
//                }
//            }
//            if(g_idirection==1)
//            {
//                if(wall_right(monster1)==true){
//                    stalking=true;
//                }
//                else{
//                monster1.X++;
//                }
//            }
//            if(g_idirection==2)
//            {
//               if(wall_down(monster1)==true){
//                    stalking=true;
//                }
//                else{
//                monster1.Y++;
//                }
//            }
//            if(g_idirection==3)
//            {
//                if(wall_up(monster1)==true){
//                    stalking=true;
//                }
//                else{
//                monster1.Y--;
//                }
//            }
//
//    }
//    if(stalking==true){
//        stalker(g_idirection,monster1,player);
//    }
//}
//

//Done By Daniel(Leader)
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


//Done By Daniel(Leader)
bool wall_left(COORD location){
    if(pacMap->data[location.Y-ciOffsetY][location.X-1-ciOffsetX] == '1'){
        return true;
    }
    else{
        return false;
    }
}


//Done By Daniel(Leader)
bool wall_right(COORD location){
    if(pacMap->data[location.Y-ciOffsetY][location.X+1-ciOffsetX] == '1'){
        return true;
    }
    else{
        return false;
    }
}


//Done By Daniel(Leader)
bool wall_up(COORD location){
    if(pacMap->data[location.Y-1-ciOffsetY][location.X-ciOffsetX] == '1'){
        return true;
    }
    else{
        return false;
    }
}


//Done By Daniel(Leader)
bool wall_down(COORD location){
    if(pacMap->data[location.Y+1-ciOffsetY][location.X-ciOffsetX] == '1'){
        return true;
    }
    else{
        return false;
    }
}
