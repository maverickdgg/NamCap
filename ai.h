#ifndef _AI_H
#define _AI_H

#include "Framework/console.h"
#include<time.h>
#include"GameUI.h"

int reroll(int& x);
void monster(COORD& ai,int& g_idirection);
//int stalker(int& direction,COORD ghost,COORD player);
//void stalker_ghost(int& g_idirection,COORD& monster1,COORD player);
bool wall_left(COORD location);
bool wall_right(COORD location);
bool wall_up(COORD location);
bool wall_down(COORD location);

#endif