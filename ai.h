#ifndef _AI_H
#define _AI_H

#include "Framework/console.h"
#include<time.h>
#include"GameUI.h"

void monster(COORD ai,int g_idirection);
bool wall_left(COORD location);
bool wall_right(COORD location);
bool wall_up(COORD location);
bool wall_down(COORD location);

#endif