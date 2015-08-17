#include"ai.h"

COORD   g_cMonster1;
bool    reverse=false;

void monster1(void){

        if(reverse==false && g_cMonster1.X<20){
            ++g_cMonster1.X;
        }
        if(g_cMonster1.X==20){
            reverse=true;
        }
        if(reverse==true && g_cMonster1.X>2){
            --g_cMonster1.X;
        }
        if(g_cMonster1.X==2){
            reverse=false;
        }
}