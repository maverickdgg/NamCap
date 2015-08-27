#ifndef _INFECTION_H
#define _INFECTION_H



struct infectants {
    //Enum gameCharacter;// player, ghost, infectants 
    COORD coordinates;
    int direction;
    bool bInfect_status;
};



void init_infection();
bool infected_win();
void moveCharacter_infection();
void infect_collision(infectants infect1,infectants infect2);
void renderCharacter_infection();


#endif