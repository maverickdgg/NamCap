#ifndef _INFECTION_H
#define _INFECTION_H

struct infectants{
    COORD coordinates;
    bool bInfect_status;
};

void init_infect();
bool infected_win();
void moveCharacter_infection();
void update_infection(double dt);
void infect_collision(infectants infect1,infectants infect2);
void renderCharacter_infection();


#endif